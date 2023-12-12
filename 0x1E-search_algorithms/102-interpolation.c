#include "search_algos.h"

/**
 * interpolation_search - a function that searches for a value in a sorted array of integers usin
 *			the Interpolation search algorithm
 * array: pointer to the given array
 * size: size of array
 * value: target to find
 *
 * Return: if SUCCESS firt index of value
 *	else -1
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t low, high, pos;

	if (array == NULL || size == 0)
		return (-1);

	for (low = 0, high = size - 1; high >= low;)
	{
		pos = low + (((double)(high - low)
					/ (array[high] - array[low])) * (value - array[low]));
		if (pos < size)
			printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", pos);
			break;
		}
		if (array[pos] == value)
			return (pos);
		else if(array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}
	return (-1);
}
