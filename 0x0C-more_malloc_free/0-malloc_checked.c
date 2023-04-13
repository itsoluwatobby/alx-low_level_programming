#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - function that allocates memory using malloc.
 * @b: given parameter
 * Return: pointer to allocated memory
 */

void *malloc_checked(unsigned int b)
{
	void *assign = malloc(b);

	if (assign == NULL)
		exit(98);

	return (assign);
}

