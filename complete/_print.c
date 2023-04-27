#include "main.h"
/**
 * _print - function that prints an argument based on its type
 * @output: formatted string that checks how to print the arguments.
 * @args: arguments passed in.
 * @i: index.
 * @buffer: array to handle print.
 * @flag: number of flags
 * @wid: width.
 * @prec: precision spec
 * @size: size
 * Return: 1 or 2;
 */
int _print(const char *output, int *i, va_list args, char buffer[],
		int flag, int wid, int prec, int size)
{
	int index, len = 0, print_char = -1;
	format_t format_type[] = {
		/*{'c', print_char},*/{'s', print_str}, {'%', print_percent},
		{'i', print_integers}, {'d', print_integers},
		{'b', print_binary}, {'u', print_unsigned_nums},
		{'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hex_upper}, {'p', print_pointer},
		{'S', print_non_printable}, {'r', print_reversal},
		{'R', print_rot13}, {'\0', NULL}
	};

	for (index = 0; format_type[index].fmt != '\0'; index++)
		if (output[*i] == format_type[index].fmt)
			return (format_type[index].fn(args, buffer, flag,
						wid, prec, size));

	if (format_type[index].fmt == '\0')
	{
		if (output[*i] == '\0')
			return (-1);
		len += write(1, "%%", 1);

		if (output[*i - 1] == ' ')
			len += write(1, " ", 1);
		else if (wid)
		{
			--(*i);

			while (output[*i] != ' ' && output[*i] != '%')
				--(*i);
			if (output[*i] == ' ')
				--(*i);

			return (1);
		}
		len += write(1, &output[*i], 1);
		return (len);
	}

	return (print_char);
}
