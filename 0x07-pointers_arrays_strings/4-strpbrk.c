#include "main.h"
/**
 * _strpbrk - function that searches a string for any
 *		of a set of bytes.
 * @s: first parameter
 * @accept: second parameter
 * Return: bytes from string
 */

char *_strpbrk(char *s, char *accept)
{
	int i = 0, j = 0;

	while (accept[i++])
	{
		while (s[j++])
		{
			if (accept[i] == s[j])
			{
				return (s + (i + 1));
			}
		}
	}
	return ('\0');
}
