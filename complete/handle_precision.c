#include "main.h"

/**
 * fetch_precision - function that calculates the precision
 * @format: formatted string
 * @i: List of arguments to be printed.
 * @args: arguments passed in.
 * Return: precision.
 */

int fetch_precision(const char *format, int *i, va_list args)
{
	int post = *i + 1;
	int precision = -1;

	if (format[post] != '.')
		return (precision);
	precision = 0;

	for (post += 1; format[post] != '\0'; post++)
	{
		if (is_digit(format[post]))
		{
			precision *= 10;
			precision += format[post] - '0';
		}
		else if (format[post] == '*')
		{
			post++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*i = post - 1;

	return (precision);
}
