#include "main.h"

/**
 * length_of_wildstr - finds the lengths of the strings
 * @str: given string
 * Return: length of str
 */

int length_of_wildstr(char *str)
{
	int length = 0, index = 0;

	if (*(str + index))
	{
		if (*str != '*')
		{
			length++;
		}

		index++;
		length += length_of_wildstr(str + index);
	}
	return (length);
}

/**
 * go_through_str - iterates a string with a wildcard
 * @string: string to iterate
 */

void go_through_str(char **string)
{
	if (**string == '*')
	{
		(*string)++;
		go_through_str(string);
	}
}

/**
 * string_after_wildcard - chacks if a character matches the
 *	character of another string after the wildcard
 * @str1: first string
 * @postfix: postfix
 * Return: if str1[i] == str2[i](pointer ot null)
 */

char *string_after_wildcard(char *str1, char *postfix)
{
	int length = length_of_wildstr(str1) - 1;
	int postfix_length = length_of_wildstr(postfix) - 1;

	if (*postfix == '*')
		go_through_str(&postfix);

	if (*(str1 + length - postfix_length) == *postfix && *postfix != '\0')
	{
		postfix++;
		return (string_after_wildcard(str1, postfix));
	}

	return (postfix);
}

/**
 * wildcmp - function that compares two strings and
 *		returns 1 if the strings can be considered
 *		identical, otherwise return 0.
 * @s1: first string to be compared
 * @s2: second string
 * Return: if identical (1), else (0)
 */

int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		go_through_str(&s2);
		s2 = string_after_wildcard(s1, s2);
	}

	if (*s2 == '\0')
		return (1);

	if (*s1 != *s2)
		return (0);

	return (wildcmp(++s1, ++s2));
}
