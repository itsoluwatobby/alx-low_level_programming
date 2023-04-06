#include "main.h"

/**
 * _puts - function that prints a string, followed by a new line,
 *	to stdout.
 * @str: parameter to print
 */

void _puts(char *str)
{
	while (*str)
		_putchar(*str++);
	_putchar('\n');
}
