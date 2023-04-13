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
	void *new_mem;

	if (new_size == 0 && ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	if (new_size > old_size)
	{
		new_mem = malloc(sizeof(int) * new_size);
		return (new_mem);
	}

	if (ptr == NULL)
	{
		new_mem = malloc(new_size);
		return (new_mem);
	}

	new_mem = realloc(ptr, new_size * sizeof(int));

	return (new_mem);
}
