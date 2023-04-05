#include "main.h"

/**
 * _stringlen - find the length of a string.
 * @s: given string.
 *
 * Return: length of string.
 */

int _stringlen(char *s)
{
	int length = 0;

	if (*(s + length))
	{
		length++;
		length += _stringlen(s + length);
	}

	return (length);
}

/**
 * checker - Checks for a palindrome.
 * @s: string to checked.
 * @length: length of s.
 * @i: index of s.
 *
 * Return: If palindrome (1), else (0).
 */

int checker(char *s, int length, int i)
{
	if (s[i] == s[length / 2])
		return (1);

	if (s[i] == s[length - i - 1])
		return (checker(s, length, i + 1));

	return (0);
}

/**
 * is_palindrome - function that returns 1 if a
 *		string is a palindrome and 0 if not
 * @s: string to check
 * Return: if palindrome(1), else(0)
 */

int is_palindrome(char *s)
{
	int i = 0;
	int length = _stringlen(s);

	if (!(*s))
		return (1);

	return (checker(s, length, i));
}
