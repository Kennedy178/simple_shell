#include <stdio.h>
#include "shell.h"

/**
 * add - sum 2 integers
 * @n1: number 1 to be summed
 * @n2: integer 2 to be summed
 *
 * Return: sum of n1 and n2
 */

int add(int n1, int n2)
{
return (n1 + n2);
}
/**
 * main - starting the program
 *
 * Return: 0 (Success)
 */
int main(void)
{
int result = add(4, 6);
printf("Result: %d\n", result);
return (0);
}
