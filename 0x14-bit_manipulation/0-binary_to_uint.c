#include "main.h"
#include <stdlib.h>
#include <math.h>

/**
 * binary_to_uint - function that converts a binary to a unsigned int
 * @b: given binary
 * Return: unsigned value
 */

unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int result = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);

		result = 2 * result + (b[i] - '0');
	}

	return (result);
}
