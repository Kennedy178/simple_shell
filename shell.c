#include "shell.h"

/**
 * main - entry point for the shell program
 * @ac: the number of command-line arguments
 * @env: an array of strings representing the environment variables
 *
 * Return: always 0
 */
int main(int ac, char **env)
{
/* If no command-line arguments are provided, start the shell */
if (ac == 1)
prompt(env);
return (0);
}
