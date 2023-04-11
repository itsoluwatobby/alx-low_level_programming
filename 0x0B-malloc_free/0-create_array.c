#include "main.h"
#include <stdlib.h>

/**
 * create_array -  function that creates an array of chars,
 *		and initializes it with a specific char.
 * @size: multiplied by data type to allocate memory space
 * @c: param to allocate space for
 * Return: pointer to array
 */

char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i = 0;

	if (size == 0)
		return (NULL);

	arr = malloc(sizeof(char) * size);

	if (arr == NULL)
		return (NULL);

	while (i < size)
	{
		arr[i] = c;
		i++;
	}

	return (arr);
}
