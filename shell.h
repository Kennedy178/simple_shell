#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * prompt - Displays a prompt for the user to enter a command.
 * @av: Pointer to a character array of arguments passed to the program.
 * @env: Pointer to a character array of environment variables.
 *
 * This function does not have a return value.
 * The purpose of this function is to display a prompt for the user to enter a command.
 * The prompt should display the current working directory followed by a dollar sign ($).
 */
void prompt(char **av, char **env);

#endif /* SHELL_H */

