#include "function_pointers.h"
#include <stddef.h>

/**
 * array_iterator - function that points to another function
 * @array: given array
 * @size: size of array
 * @action: function parameter
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array == NULL || size <= 0 || action == NULL)
		return;

	for (size_t i = 0; i < size; i++)
		action(array[i]);
}
