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
	unsigned int i = 0, j = 0, len1 = 0, len2 = 0;

	while (s1 && s1[len1])
		len1++;

	while (s2 && s2[len2])
		len2++;

	if (n < len2)
		new_value = malloc(sizeof(char) * (len1 + len2 + 1));

	else
		new_value = malloc(sizeof(char) * (len2 + len1 + 1));

	if (new_value == NULL)
		return (NULL);

	while (i < len1)
	{
		new_value[i] = s1[i];
		i++;
	}

	while (n < len2 && i < (len1 + n))
		new_value[i++] = s2[j++];

	while (n >= len2 && i < (len1 + len2))
		new_value[i++] = s2[j++];

	new_value[i] = '\0';

	return (new_value);
}
