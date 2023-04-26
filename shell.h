#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * prompt - Displays a prompt for the user to enter a command.
 * shell_exit - exits shell
 * execute_command - command not found or found
 * my_env - Implement the env built-in, that prints the current environment
 * my_getline -  reads input from a stream and stores it in a buffer.
 * change_dir - changes the current working directory of the process
 * set_env_var - sets the value of an environment variable.
 * get_env_var - gets the value of an environment variable.
 * cd - changing directory
 * non_interactive - executes non-interactive shell commands
 * @input: the command input string
 * @env: the environment variables
 * args - arguments
 * @env: Pointer to a character array of environment variables.
 * This function does not have a return value.
 * The purpose of this function is to display a prompt for the user to enter a command.
 * The prompt should display the current working directory followed by a dollar sign ($).
 */

void prompt(char **env);
void shell_exit();
void execute_command(char **args);
void my_env();
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
void cd(char *dir);
void non_interactive(char *input, char **env);

#endif /* SHELL_H */

