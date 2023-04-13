#include "main.h"
#include <stdlib.h>

/**
 * _realloc - function that reallocates a memory block
 *		using malloc and free.
 * @ptr: pointer to the array
 * @old_size: previous size
 * @new_size: new size to allocate
 * Return: pointer to reallocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_mem;
	char *copy;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (new_size == old_size && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	new_mem = malloc(new_size);

	if (!new_mem)
		return (NULL);

	copy = ptr;

	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new_mem[i] = copy[i];
	}

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new_mem[i] = copy[i];
	}

	free(ptr);

	return (new_mem);
}
