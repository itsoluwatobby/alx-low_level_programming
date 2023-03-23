#include "main.h"
/**
 * print_diagonal - function that draws a diagonal line on the terminal.
 * @n: number of times to repeat diagonal
 */
void print_diagonal(int n)
{
	int i;
	int k;

	if (n <= 0)
		_putchar('\n');
	else
	{
		for (k = 0; k < n; k++)
		{
			for (i = 0; i < k; i++)
				_putchar(' ');
			_putchar('\\');

			if (k == n - 1)
				continue;

			_putchar('\n');
		}
		_putchar('\n');
	}
}
