#include "shell.h"
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND 10

/**
* prompt - Simple shell prompt that reads input and executes commands
* my_env - prints my environment
* execute_command - responsible with paths
* @av: Array of strings representing command-line arguments
* @env: Array of strings representing environment variables
* execute_command - path related
* @args: pointer to an array that represents the command and its arguments.
*/

extern char **environ;
void execute_command(char **args) {
char **env = environ;
char *path;
char *dir;
char *p;
pid_t pid;
if (strcmp(args[0], "env") == 0) {
while (*env) {
printf("%s\n", *env++);
}
return;
}
path = getenv("PATH");
p = strtok(path, ":");
 while (p != NULL) {
dir = malloc(strlen(p) + strlen(args[0]) + 2);
sprintf(dir, "%s/%s", p, args[0]);
if (access(dir, X_OK) == 0) {
pid = fork();
if (pid == 0) {
execv(dir, args);
perror("execv");
exit(EXIT_FAILURE);
} else if (pid > 0) {
waitpid(pid, NULL, 0);
free(dir);
return;
} else {
perror("fork");
exit(EXIT_FAILURE);
}
}
free(dir);
p = strtok(NULL, ":");
}
printf("%s: command not found\n", args[0]);
return;
}
void my_env() {
extern char **environ;
int i = 0;
while (environ[i] != NULL) {
printf("%s\n", environ[i++]);
}
}
void prompt(char **env)
{
char *string = NULL;
int state;
int pn;
size_t km = 0;
ssize_t ken_size;
char *argv[MAX_COMMAND];
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
/*Check for exit command*/
if (strcmp(string, "exit") == 0) {
free(string);
shell_exit();
}
/* Set the command to be executed */
pn = 0;
argv[pn] = strtok(string, " ");
while (argv[pn] && pn < MAX_COMMAND - 1) {
argv[++pn] = strtok(NULL, " ");
}
 /* Execute the command */
execute_command(argv);
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
/*Check for exit command*/
if (strcmp(string, "exit") == 0) {
free(string);
shell_exit();
}
/* Set the command to be executed */
argv[0] = string;
/* Execute the command */
execute_command(argv);
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
