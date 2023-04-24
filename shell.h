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
 * args - arguments
 * @env: Pointer to a character array of environment variables.
 *
 * This function does not have a return value.
 * The purpose of this function is to display a prompt for the user to enter a command.
 * The prompt should display the current working directory followed by a dollar sign ($).
 */
void prompt(char **env);
void shell_exit();
void execute_command(char **args);

#endif /* SHELL_H */

