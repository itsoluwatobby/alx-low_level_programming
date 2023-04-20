#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - function that prints numbers
 * @separator: first parameter
 * @n: number of arguments passed
 * @...: parameters passed into the function
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list entry;
	unsigned int index;

	va_start(entry, n);

	for (index = 0; index < n; index++)
	{
		printf("%d", va_arg(entry, int));

		if (index != (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");

	va_end(entry);
}
