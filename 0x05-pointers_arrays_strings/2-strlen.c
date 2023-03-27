#include "main.h"
#include <string.h>

/**
 * _strlen - function that returns the length of a string.
 * @s: length to be returned
 * Return: on success (s)
 */

int _strlen(char *s)
{
	int size = 0;

	while (*s++)
		size++;

	return (size);
}
