#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat -  function that concatenates two strings.
 * @s1: first parameter
 * @s2: second parameter
 * @n: third parameter
 * Return: concatenated string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *new_value;
	unsigned int len = n;
	unsigned int index;

	if (s1 == NULL)
		s1 = "";

	else if (s2 == NULL)
		s2 = "";

	for (index = 0; s1[index]; index++)
		len++;

	new_value = malloc(sizeof(char) * (len + 1));

	if (new_value == NULL)
		return (NULL);

	len = 0;

	if (n >= strlen(s2))
	{
		for (index = 0; s1[index]; index++)
			new_value[len++] = s1[index];

		for (index = 0; s2[index]; index++)
			new_value[len++] = s2[index];
	}
	else
	{
		for (index = 0; s1[index]; index++)
			new_value[len++] = s1[index];

		for (index = 0; index < n; index++)
			new_value[len++] = s2[index];
	}

	new_value[len + 1] = '\0';

	return (new_value);
}
