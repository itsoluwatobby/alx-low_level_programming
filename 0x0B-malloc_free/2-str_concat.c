#include "main.h"
#include <stdlib.h>

/**
 * str_concat - function that concatenates two strings.
 * @s1: first param
 * @s2: second param
 * Return: resulting strings
 */

char *str_concat(char *s1, char *s2)
{
	char *concat;
	int i, len = 0, str_len = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] || s2[i]; i++)
		len++;

	concat = malloc(sizeof(char) * len);

	if (concat == NULL)
		return (NULL);

	for (i = 0; s1[i]; i++)
		concat[str_len++] = s1[i];

	for (i = 0; s2[i]; i++)
		concat[str_len++] = s2[i];

	return (concat);
}
