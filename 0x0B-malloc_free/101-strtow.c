#include "main.h"
#include <stdlib.h>

int word_length(char *str);
int words_count(char *str);

/**
 * word_length - function that counts the number of words
 *		in a string leaving out spaces.
 * @str: string to be counted.
 * Return: length of the string.
 */

int word_length(char *str)
{
	int i = 0, len = 0;

	while (*(str + i) && *(str + i) != ' ')
	{
		len++;
		i++;
	}

	return (len);
}

/**
 * words_count - Counts the number of words in a
 *		statement.
 * @str: words to be counted.
 * Return: number of words.
 */

int words_count(char *str)
{
	int i = 0, words = 0, len = 0;

	for (i = 0; *(str + i); i++)
		len++;

	for (i = 0; i < len; i++)
	{
		if (*(str + i) != ' ')
		{
			words++;
			i += word_length(str + i);
		}
	}

	return (words);
}

/**
 * strtow - function that splits a string into words.
 * @str: string to split.
 * Return: pointer to an array of strings (words).
 */

char **strtow(char *str)
{
	char **new_string;
	int i = 0, words, w, letter, j;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	words = words_count(str);
	if (words == 0)
		return (NULL);

	new_string = malloc(sizeof(char *) * (words + 1));
	if (new_string == NULL)
		return (NULL);

	for (w = 0; w < words; w++)
	{
		while (str[i] == ' ')
			i++;

		letter = word_length(str + i);

		new_string[w] = malloc(sizeof(char) * (letter + 1));

		if (new_string[w] == NULL)
		{
			for (; w >= 0; w--)
				free(new_string[w]);

			free(new_string);
			return (NULL);
		}

		for (j = 0; j < letter; j++)
			new_string[w][j] = str[i++];

		new_string[w][j] = '\0';
	}
	new_string[w] = NULL;

	return (new_string);
}
