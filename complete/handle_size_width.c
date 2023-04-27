#include "main.h"

/**
 * fetch_size - function that gets the size to cast the argument
 * @format: formatted string
 * @i: List of arguments to be printed.
 * Return: size.
 */
int fetch_size(const char *format, int *i)
{
	int post = *i + 1;
	int size = 0;

	if (format[post] == 'l')
		size = LONG;
	else if (format[post] == 'h')
		size = SHORT;
	if (size == 0)
		*i = post - 1;
	else
		*i = post;

	return (size);
}

/**
 * fetch_width - function that evaluates the width
 * @format: formatted string.
 * @i: List of arguments to be printed.
 * @args: arguments passed in.
 * Return: width.
 */
int fetch_width(const char *format, int *i, va_list args)
{
	int post;
	int wid = 0;

	for (post = *i + 1; format[post] != '\0'; post++)
	{
		if (is_digit(format[post]))
		{
			wid *= 10;
			wid += format[post] - '0';
		}
		else if (format[post] == '*')
		{
			post++;
			wid = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*i = post - 1;

	return (wid);
}
