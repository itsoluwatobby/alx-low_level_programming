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
	unsigned int index = 0;

	if (array == NULL || size <= 0 || action == NULL)
		return;

	while (index < size)
	{
		action(array[index]);
		index++;
	}
}
