#include "function_pointers.h"

/**
 * int_index - function that searches for an integer.
 * @array: given array
 * @size: size of the array
 * @cmp: function parameter
 * Return: an integer
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (array == NULL || cmp == NULL)
		return (-1);

	if (size <= 0)
		return (-1);

	while (i < size)
	{
		if (cmp(array[i]) != 0)
			return (i);
		i++;
	}

	return (-1);
}
