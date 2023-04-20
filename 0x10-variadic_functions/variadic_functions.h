#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>
#include <stdio.h>

/**
 * struct printAll - struct type defining a printAll.
 * @symbol: symbol of a data type.
 * @print: function pointer that points to a function that prints
 *         a data type matching to the symbol.
 */
typedef struct printAll
{
	char *symbol;
	void (*print)(va_list arg);

} printAll_t;

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
int _putchar(char c);

#endif
