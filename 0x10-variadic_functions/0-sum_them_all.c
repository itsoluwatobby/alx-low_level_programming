#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - function that returns the sum of all
 *		its parameters
 * @n: number of arguments passed
 * @...: arguments passed to the function.
 * Return: sum of arguments
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
