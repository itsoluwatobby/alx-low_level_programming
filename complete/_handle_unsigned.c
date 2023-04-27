#include "main.h"

/**
 * print_unsigned_nums - function that prints an unsigned numbers
 * @args: arguments passed
 * @buffer: array of chars
 * @flag: number of flag
 * @wid: width.
 * @prec: precision spec
 * @size: size
 * Return: required output
 */

int print_unsigned_nums(va_list args, char buffer[], int flag, int wid,
		int prec, int size)
{
	int i = BYTE_SIZE - 2;
	unsigned long int number = va_arg(args, unsigned long int);

	number = convert_unsigned_size(number, size);
	if (number == 0)
		buffer[i--] = '0';
	buffer[BYTE_SIZE - 1] = '\0';

	while (number >= 1)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}
	i++;

	return (write_unsigned_val(0, i, buffer, flag, wid, prec, size));
}


/**
 * print_octal - function that prints an unsigned number in octal notation
 * @args: arguments passed
 * @buffer: array of chars
 * @flag: number of flag
 * @wid: width.
 * @prec: precision spec
 * @size: size
 * Return: required output
 */

int print_octal(va_list args, char buffer[], int flag, int wid, int prec,
		int size)
{
	int i = BYTE_SIZE - 2;
	unsigned long int number = va_arg(args, unsigned long int);
	unsigned long int token = number;

	UNUSED(wid);
	number = convert_unsigned_size(number, size);

	if (number == 0)
		buffer[i--] = '0';
	buffer[BYTE_SIZE - 1] = '\0';
	while (number >= 1)
	{
		buffer[i--] = (number % 8) + '0';
		number /= 8;
	}
	if (flag & HASH_SIGN && token != 0)
		buffer[i--] = '0';
	i++;

	return (write_unsigned_val(0, i, buffer, flag, wid, prec, size));
}

/**
 * print_hexadecimal - function that prints an unsigned number
 *		in hexadecimal notation
 * @args: arguments passed
 * @buffer: array of chars
 * @flag: number of flag
 * @wid: width.
 * @prec: precision spec
 * @size: size
 * Return: required output
 */

int print_hexadecimal(va_list args, char buffer[], int flag, int wid,
		int prec, int size)
{
	return (print_hex_result(args, "0123456789abcdef", buffer, flag,
				'x', wid, prec, size));
}

/**
 * print_hex_upper - function that prints an unsigned number in uppercase
 *			hexadecimal notation
 * @args: arguments passed
 * @buffer: array of chars
 * @flag: number of flag
 * @wid: width.
 * @prec: precision spec
 * @size: size
 * Return: required output
 */

int print_hex_upper(va_list args, char buffer[], int flag, int wid,
		int prec, int size)
{
	return (print_hex_result(args, "0123456789ABCDEF", buffer, flag,
				'X', wid, prec, size));
}

/**
 * print_hex_result - function that prints a hexadecimal number
 *			in lower or uppercase
 * @args: arguments passed
 * @buffer: array of chars
 * @hex_value: array of hexadecimal characters
 * @flag_char: hex_val (X) notation
 * @flag: number of flag
 * @wid: width.
 * @prec: precision spec
 * @size: size
 * Return: required output
 */

int print_hex_result(va_list args, char hex_value[], char buffer[],
		int flag, char flag_char, int wid, int prec, int size)
{
	int i = BYTE_SIZE - 2;
	unsigned long int number = va_arg(args, unsigned long int);
	unsigned long int token = number;

	UNUSED(wid);
	number = convert_unsigned_size(number, size);
	if (number == 0)
		buffer[i--] = '0';
	buffer[BYTE_SIZE - 1] = '\0';
	while (number >= 1)
	{
		buffer[i--] = hex_value[number % 16];
		number /= 16;
	}
	if (flag & HASH_SIGN && token != 0)
	{
		buffer[i--] = flag_char;
		buffer[i--] = '0';
	}
	i++;

	return (write_unsigned_val(0, i, buffer, flag, wid, prec, size));
}
