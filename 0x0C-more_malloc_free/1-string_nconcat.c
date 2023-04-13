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
	unsigned int s1_len = strlen(s1), s2_len = strlen(s2);
	unsigned int i = 0, index;

	if (s1 == NULL)
		s1 = "";
	else if (s2 == NULL)
		s2 = "";

	new_value = malloc(s1_len + s2_len + 1);

	if (new_value == NULL)
		return (NULL);

	if (n >= s2_len)
	{
		for (index = 0; s1[index]; index++)
			new_value[i++] = s1[index];

		for (index = 0; s2[index]; index++)
			new_value[i++] = s2[index];
	}
	else
	{
		for (index = 0; s1[index]; index++)
			new_value[i++] = s1[index];

		for (index = 0; index < n; index++)
			new_value[i++] = s2[index];
	}

	return (new_value);
}
