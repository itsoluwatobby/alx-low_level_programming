#include "main.h"

void cleanup(char buffer[], int *index);

/**
 * _printf - function that performs like the built-in printf function
 * @format: format.
 * Return: print output.
 */

int _printf(const char *format, ...)
{
	int i, result = 0, print_char = 0;
	int flag, wid, prec, size, index = 0;
	va_list args;
	char buffer[BYTE_SIZE];

	if (format == NULL)
		return (-1);
	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[index++] = format[i];
			if (index == BYTE_SIZE)
				cleanup(buffer, &index);
			print_char++;
		}
		else
		{
			cleanup(buffer, &index);
			flag = fetch_flags(format, &i);
			wid = fetch_width(format, &i, args);
			prec = fetch_precision(format, &i, args);
			size = fetch_size(format, &i);

			++i;
			result = _print(format, &i, args, buffer, flag,
					wid, prec, size);
			if (result == -1)
				return (-1);

			print_char += result;
		}
	}
	cleanup(buffer, &index);
	va_end(args);

	return (print_char);
}

/**
 * cleanup - function that prints elements of a buffer
 * @buffer: array of characters
 * @index: Index.
 */

void cleanup(char buffer[], int *index)
{
	if (*index > 0)
		write(1, &buffer[0], *index);
	*index = 0;
}

