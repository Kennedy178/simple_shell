#include "shell.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/** 
 * shell_exit - a function that exists the shell
 * 
 */

void shell_exit() {
printf("Exiting shell...\n");
exit(EXIT_SUCCESS);
}

