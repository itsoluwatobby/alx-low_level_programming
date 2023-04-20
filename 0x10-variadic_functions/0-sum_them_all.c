#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - function that returns the sum of all
 *		its parameters.
 * @n: given parameter
 * @...: paramters to calculate the sum of
 * Return: sum of all passed arguments
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list entry;
	unsigned int i, total_sum = 0;

	va_start(entry, n);

	if (n == 0)
		return (0);

	for (i = 0; i < n; i++)
		total_sum += va_arg(entry, int);
	va_end(entry);

	return (total_sum);
}
