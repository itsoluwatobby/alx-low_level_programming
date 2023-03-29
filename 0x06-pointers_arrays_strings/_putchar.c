#include <stdio.h>
#include <unistd.h>

/**
 * _putchar - prints the result to the stdout.
 * @c: parameter to be printed
 * Return: on success (1), on error (-1)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
