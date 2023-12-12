#include "search_algos.h"

int advanced_binary_recur(int *array, size_t left,  size_t right, int value);

/**
 * advanced_binary_recur - A recursive function for the
 *			advances_binary search algorithm
 * @array: sorted array to search from
 * @left: size of the array
 * @right: size of the array
 * @value: target to be found
 *
 * Return: if SUCCESS index of the value else -1
 */
int advanced_binary_recur(int *array, size_t left,  size_t right, int value)
{
	size_t mid;
	int mid_val;

	if (left > right)
		return (-1);

	printf("Searching in array: ");
	for (mid = left; mid < right; mid++)
		printf("%d, ", array[mid]);
	printf("%d\n", array[mid]);

	mid = left + ((right - left) / 2);
	mid_val = array[mid];
	if (mid_val == value && (mid == left || array[mid - 1] != value))
		return (mid);
	if (mid_val >= value)
		return (advanced_binary_recur(array, left, mid, value));
	return (advanced_binary_recur(array, mid + 1, right, value));
}

/**
 * advanced_binary - A function that searches for a value in a sorted array
 *              of integers using the binary search algorithm
 * @array: Sorted array to search from
 * @size: size of the array
 * @value: target to be found
 *
 * Return: if SUCCESS index of the value else -1
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (advanced_binary_recur(array, 0, size - 1, value));
}
