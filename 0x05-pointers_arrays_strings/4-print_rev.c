#include "main.h"

/**
 * print_rev - function that prints a string, in reverse,
 *		followed by a new line.
 * @s: string to be printed
 */

void print_rev(char *s)
{
	int total = 0;
	int index;

	while (*s)
		total++;

	for (index = total; index >= 0; index--)
	{
		char a = s[index];

		_putchar(a);
	}

	_putchar('\n');
}
