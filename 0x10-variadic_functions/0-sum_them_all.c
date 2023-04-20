#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - function that returns the sum of all
 *		its parameters.
 * @n: given parameter
 * @...: paramters to calculate the sum of
 * Return: sum of passed arguments
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int index, total_sum = 0;

	va_start(args, n);

	for (index = 0; index < n; index++)
		total_sum += va_arg(args, int);

	va_end(args);

	return (total_sum);
}
