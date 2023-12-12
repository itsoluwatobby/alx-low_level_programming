#include "search_algos.h"

int binary_search_algo(int *array, int low, int high, int value);

/**
 * binary_search_algo - a function that searches for a value in a sorted array of integers usin
 *			the Binary search algorithm
 * array: pointer to the given array
 * low: start index
 * high: end index
 * target: target to find
 *
 * Return: if SUCCESS firt index of value | else -1
*/
int binary_search_algo(int *array, int low, int high, int target)
{
	int mid, mid_val;

	if (array == NULL)
		return (-1);

	while (low <= high)
	{
		printf("Searching in array: ");
		for (mid = low; mid <= high; mid++)
		{
			printf("%d", array[mid]);
			(mid != high) ? printf(", ") : printf("\n");
		}
		mid = low + (high - low) / 2;
		mid_val = array[mid];

		if (mid_val == target)
			return (mid);
		else if (mid_val < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

/**
 * exponential_search - a function that searches for a value in a sorted array of integers usin
 *                      the Exponential search algorithm
 * array: pointer to the given array
 * size: size of array
 * value: target to find
 *
 * Return: if SUCCESS first index of value | else -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bnd;
	int low, high, result;

	if (array == NULL || size == 0)
		return (-1);

	if (array[0] != value)
	{
		for (bnd = 1; bnd < size && array[bnd] <= value; bnd *= 2)
			printf("Value checked array[%ld] = [%d]\n", bnd, array[bnd]);
			
	}
	low = bnd / 2;
	high =  (bnd < size) ? bnd : size - 1;
	printf("Value found between indexes [%d] and [%d]\n", low, high);
	result = binary_search_algo(array, low, high, value);
	return (result);
}
