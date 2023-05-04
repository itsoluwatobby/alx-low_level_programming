#include "main.h"

/**
 * flip_bits - function that returns the number of bits you would
 *		need to flip to get from one number to another
 * @n: given number
 * @m: amount to flip
 * Return: amount
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int pres, unit = n ^ m;
	int count = 0, bit = 63;

	while (bit >= 0)
	{
		pres = unit >> bit;
		if (pres & 1)
			count++;
		bit--;
	}

	return (count);
}
