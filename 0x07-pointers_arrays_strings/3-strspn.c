#include "main.h"
/**
 * _strspn - unction that gets the length of a prefix substring.
 * @s: first parameter
 * @accept: second parameter
 * Return: length
 */

unsigned int _strspn(char *s, char *accept)
{
	int j = 0;
	int x = 0;
	int y = 0;

	while (accept[j++])
	{
		x = 0;

		while (s[x++])
		{
			if (accept[j] == s[x])
				y++;
		}
	}

	return (y);
}
