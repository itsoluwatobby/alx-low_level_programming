#include "main.h"

/**
 * fetch_flags - function that evaluate the current flags
 * @format: formatted string
 * @i: take a parameter.
 * Return: Flags:
 */
int fetch_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, post;
	int flags = 0;
	const char KNOWN_CHAR_FLAGS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int KNOWN_INT_FLAGS[] = {MINUS_SIGN, PLUS_SIGN, ZERO,
		HASH_SIGN, SPACE, 0};

	for (post = *i + 1; format[post] != '\0'; post++)
	{
		for (j = 0; KNOWN_CHAR_FLAGS[j] != '\0'; j++)
			if (format[post] == KNOWN_CHAR_FLAGS[j])
			{
				flags |= KNOWN_INT_FLAGS[j];
				break;
			}
		if (KNOWN_CHAR_FLAGS[j] == 0)
			break;
	}
	*i = post - 1;

	return (flags);
}

