#include "main.h"

/**
 * set_bit - function that sets the value of a bit to 1 at a given index.
 * @n: given number
 * @index: starting from 0
 * Return: 1 on success, else -1
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= 64)
		return (-1);
	*n = (1UL << index) | *n;
	return (1);
}
