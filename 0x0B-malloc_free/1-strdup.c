#include "main.h"
#include <stdlib.h>

/**
 * _strdup - function that returns a pointer to a newly
 *	allocated space in memory, which contains a copy
 *	of the string given as a parameter.
 * @str: string given
 * Return: string str
 */

char *_strdup(char *str)
{
	int i, len = 0;
	char *copy;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		len++;

	copy = malloc(sizeof(char) * (len + 1));

	if (copy == NULL)
		return (NULL);

	i = 0;
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}

	copy[len] = '\0';
	return (copy);
}
