#include "main.h"

/**
 * print_binary - function that prints the binary representation of a number
 * @n: given number
 */

void print_binary(unsigned long int n)
{
	int i = 0, bit = 63, count = 0;

	for (i = bit; i >= 0; i--)
	{
		if ((n >> i) & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
