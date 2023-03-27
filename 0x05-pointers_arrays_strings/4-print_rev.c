#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * print_rev - function that prints a string, in reverse,
 *		followed by a new line.
 * @s: string to be printed
 */

void print_rev(char *s)
{
	int len;
	int index;

	len = strlen(s);

	for (index = len; index >= 0; index--)
	{
		_putchar(s[index]);
	}

	_putchar('\n');
}
