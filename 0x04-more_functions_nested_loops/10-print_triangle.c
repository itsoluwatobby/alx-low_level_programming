#include "main.h"
/**
 * print_triangle - function that prints a triangle
 * @size: size of the triangle
 */
void print_triangle(int size)
{
	int i;
	int k;

	if (size > 0)
	{
		for (i = 1; i <= size; i++)
		{
			for (k = size - i; k > 0; k--)
				_putchar(' ');

			for (k = 0; k < i; k++)
				_putchar('#');

			if (i == size)
				continue;

			_putchar('\n');
		}
	}
	_putchar('\n');
}
