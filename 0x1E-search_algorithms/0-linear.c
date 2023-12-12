#include "search_algos.h"

/**
 * linear_search - A function that searches for a value in an array
 *		of integers using the linear search
 * @array: Array of integers passed as an arg
 * @size: original lenght of the array
 * @value: target to be searched
 *
 * Return: first index of the target if SUCCESS
 *	else (absent/NULL) -1
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	if (size == 0)
		return (-1);
	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
