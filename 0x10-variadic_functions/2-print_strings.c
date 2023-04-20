#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings -  function that prints strings
 * @separator: given string
 * @n: number of parameters passed in
 * @...: parameters passed to function
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list entry;
	char *str;
	unsigned int index;

	va_start(entry, n);
	for (index = 0; index < n; index++)
	{
		str = va_arg(entry, char *);

		if (str == NULL)
			printf("nil");
		else
			printf("%s", str);

		if (index != (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");

	va_end(entry);
}
