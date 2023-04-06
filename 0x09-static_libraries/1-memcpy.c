#include "main.h"
/**
 * _memcpy - function that copies memory area.
 * @dest: first parameter
 * @src: second parameter
 * @n: third parameter
 * Return: memory copy
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int index;
	int con = n;

	for (index = 0; index < con; index++)
	{
		dest[index] = src[index];
		n--;
	}
	return (dest);
}
