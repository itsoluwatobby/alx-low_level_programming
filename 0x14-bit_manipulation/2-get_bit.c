#include "main.h"

/**
 * get_bit - function that returns the value of a bit at a given index.
 * @n: given number
 * @index: starting from 0
 * Return: value of bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bit;

	if (index >= 64)
		return (-1);
	bit = (n >> index) & 1;
	return (bit);
}
