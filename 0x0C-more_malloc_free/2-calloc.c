#include "main.h"
#include <stdlib.h>

/**
 * _calloc - function that allocates memory for an array,
 *		using malloc.
 * @nmemb: number of element in array
 * @size: size of array element data type
 * Return: pointer to array
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *arr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	arr = calloc(nmemb, size);

	if (arr == NULL)
		return (NULL);

	return (arr);
}
