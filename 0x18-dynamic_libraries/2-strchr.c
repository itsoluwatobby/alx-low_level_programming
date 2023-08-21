#include "main.h"
/**
 * _strchr - function that locates a character in a string
 * @s: first parameter
 * @c: second parameter
 * Return: a character
 */

char *_strchr(char *s, char c)
{
	int index = 0;

	while (s[index++])
	{
		if (s[index] == c)
			return (s + index);
	}

	return ('\0');
}
