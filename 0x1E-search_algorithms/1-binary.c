#include "search_algos.h"

/**
 * binary_search - A function that searches for a value in a sorted array
 *		of integers using the binary search algorithm
 * @array: Sorted array to search from
 * @size: size of the array
 * @value: target to be found
 *
 * Return: if SUCCESS index of the value else -1
 */

int binary_search(int *array, size_t size, int value)
{
	int mid_value = 0, index = 0, middle = 0, start = 0, end = size - 1;

	if (size == 0)
		return (-1);

	while (start <= end)
	{
		printf("Searching in array: ");
		for (index = start; index <= end; index++)
		{
			printf("%d", array[index]);
			if (index != end)
				printf(", ");
			else
				printf("\n");
		}
		middle = start + ((end - start) / 2);
		mid_value = array[middle];
		/* check if the value is on the right side */
		if (mid_value < value)
			start = middle + 1;
		/* check if the value is on the left side */
		else if (mid_value > value)
			end = middle - 1;
		else
			return (middle);
	}
	return (-1);
}
