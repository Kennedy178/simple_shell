#include "shell.h"
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
* prompt - Simple shell prompt that reads input and executes commands
* @av: Array of strings representing command-line arguments
* @env: Array of strings representing environment variables
*/
void prompt(char **env)
{
char *string = NULL;
int state;
size_t km = 0;
ssize_t ken_size;
char *argv[2] = {NULL, NULL};
/* Create child */
pid_t inherit_pid;

/* Check if running in interactive mode */
if (isatty(STDIN_FILENO))
{
while (1)
{
/* Print prompt to ask user for input */
printf("ken_shell$ ");

/* Read input from user */
ken_size = getline(&string, &km, stdin);

/* Handle errors */
if (ken_size == -1)
{
free(string);
exit(EXIT_FAILURE);
}

/* Remove newline character from input string */
string[strcspn(string, "\n")] = '\0';

/* Set the command to be executed */
argv[0] = string;

/* Create child process to execute the command */
inherit_pid = fork();
if (inherit_pid == -1)
{
free(string);
perror("fork");
exit(EXIT_FAILURE);
}

if (inherit_pid == 0)
{
/* Child process: execute the command */
if (execve(argv[0], argv, env) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
/* Parent process: wait for child process to finalize */
wait(&state);
}
}
}
else /* Non-interactive mode*/
{
/* Read input from standard input */
ken_size = getline(&string, &km, stdin);

/* Handle errors */
if (ken_size == -1)
{
free(string);
exit(EXIT_FAILURE);
}

/* Remove newline character from input string */
string[strcspn(string, "\n")] = '\0';

/* Set the command to be executed */
argv[0] = string;

/* Create child process n execute command */
inherit_pid = fork();
if (inherit_pid == -1)
{
free(string);
perror("fork");
exit(EXIT_FAILURE);
}

if (inherit_pid == 0)
{
/* Child process: execute the command */
if (execve(argv[0], argv, env) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
/* Parent process: wait for child process to complete*/
wait(&state);
}

/* Free memory & exit */
free(string);
exit(EXIT_SUCCESS);
}
}

