#include "main.h"
/**
 * _memset - function that fills memory with a constant byte.
 * @s: first parameter
 * @b: second parameter
 * @n: third parameter
 * Return: pointer to s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int index;

	for (index = 0; n > 0; index++)
	{
		s[index] = b;
		n--;
	}

	return (s);
}
