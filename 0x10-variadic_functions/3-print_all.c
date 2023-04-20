#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

void print_char(va_list arg);
void print_int(va_list arg);
void print_float(va_list arg);
void print_string(va_list arg);

/**
 * print_char - function that prints a character.
 * @character: list of arguments pointing to the characters
 */

void print_char(va_list character)
{
	char chr;

	chr = va_arg(character, int);
	printf("%c", chr);
}


/**
 * print_int - function that prints an integer.
 * @numbers: list of arguments pointing to the integers
 */
void print_int(va_list numbers)
{
	int nums;

	nums = va_arg(numbers, int);
	printf("%d", nums);
}


/**
 * print_float - function that prints a float.
 * @arg: list of arguments pointing to numbers with
 *	floating points
 */

void print_float(va_list arg)
{
	float nums;

	nums = va_arg(arg, double);
	printf("%f", nums);
}


/**
 * print_string - function that prints a string.
 * @strings: list of arguments pointing to a string
 */

void print_string(va_list strings)
{
	char *str;

	str = va_arg(strings, char *);

	if (str == NULL)
	{
		printf("(nil)");
		return;
	}

	printf("%s", str);
}


/**
 * print_all - function that prints anything
 * @format: characters representing  argument types.
 * @...: number of arguments passed to function.
 *
 */

void print_all(const char * const format, ...)
{
	va_list entry;
	char *separator = "";
	int i = 0, j = 0;

	printAll_t functions[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string}
	};

	va_start(entry, format);

	while (format && (*(format + i)))
	{
		j = 0;

		while (j < 4 && (*(format + i) != *(functions[j].symbol)))
			j++;

		if (j < 4)
		{
			printf("%s", separator);
			functions[j].print(entry);
			separator = ", ";
		}

		i++;
	}

	printf("\n");

	va_end(entry);
}
