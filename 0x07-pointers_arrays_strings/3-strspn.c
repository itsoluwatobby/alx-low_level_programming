#include "main.h"
/**
 * _strspn - unction that gets the length of a prefix substring.
 * @s: first parameter
 * @accept: second parameter
 * Return: length
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int b = 0;
	int index;

	while (*s)
	{
		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
			{
				b++;
				break;
			}

			else if (accept[index + 1] == '\0')
				return (b);
		}
		s++;
	}

	return (b);
}
