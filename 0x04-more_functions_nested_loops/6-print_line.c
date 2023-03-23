#include "main.h"
/**
 * print_line - function that draws a straight line in the terminal.
 * @n: number of times to draw
 */
void print_line(int n)
{
	if (n <= 0)
		_putchar('\n');
	else if (n > 0)
	{
		while (n--)
		{
			_putchar('_');
		}
		_putchar('\n');
	}
}
