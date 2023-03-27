#include <stdio.h>
#include <unistd.h>

/**
 * _putchar - prints out a character to stdout
 * @c: parameter to be printed
 * Return: on success i, on error 0
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
