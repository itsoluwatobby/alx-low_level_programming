#include "main.h"
/**
 * _strstr - function that locates a substring.
 * @haystack: first parameter
 * @needle: second parameter
 * Return: the substring
 */

char *_strstr(char *haystack, char *needle)
{
	int i = 0, j = 0;

	while (needle[i++])
	{
		while (haystack[j++])
		{
			if (needle[i] == haystack[j])
				return (needle);
		}
	}

	return ('\0');
}
