#include "main.h"

/**
 * print_char - function that ouputs a given character
 * @args: passed arguments
 * @buffer: array of args
 * @flag: number flags
 * @wid: width
 * @prec: position spec
 * @size: size
 * Return: required output
 */

int print_char(va_list args, char buffer[], int flag, int wid, int prec,
		int size)
{
	char arg = va_arg(args, int);

	return (handles_write_char(arg, buffer, flag, wid, prec, size));
}

/**
 * print_str - function that prints a string
 * @args: arguments passed
 * @buffer: array of characters
 * @flag:  number of flags
 * @wid: width.
 * @prec: precision spec
 * @size: size
 * Return: required output
 */
int print_str(va_list args, char buffer[], int flag, int wid, int prec,
		int size)
{
	int len = 0, index;
	char *str = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (prec >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (prec >= 0 && prec < len)
		len = prec;
	if (wid > len)
	{
		if (flag & MINUS_SIGN)
		{
			write(1, &str[0], len);
			for (index = wid - len; index > 0; index--)
				write(1, " ", 1);
			return (wid);
		}
		else
		{
			for (index = wid - len; index > 0; index--)
				write(1, " ", 1);
			write(1, &str[0], len);

			return (wid);
		}
	}

	return (write(1, str, len));
}


/**
 * print_percent - function that prints the percent sign
 * @args: arguments passed
 * @buffer: array of chars
 * @flag: number of flags
 * @wid: width.
 * @prec: precision spec
 * @size: size
 * Return: required output
 */

int print_percent(va_list args, char buffer[], int flag, int wid, int prec,
		int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(prec);
	UNUSED(size);

	return (write(1, "%%", 1));
}

/**
 * print_integers - function that print integers
 * @args: arguments passed
 * @buffer: array of chars
 * @flag: number of flags
 * @wid: width.
 * @prec: precision spec
 * @size: size
 * Return: required output
 */

int print_integers(va_list args, char buffer[], int flag, int wid,
		int prec, int size)
{
	int SIZE = BYTE_SIZE - 2, is_neg = 0;
	long int arg = va_arg(args, long int);
	unsigned long int number;

	arg = convert_int_size(arg, size);

	if (arg == 0)
		buffer[SIZE--] = '0';
	buffer[BYTE_SIZE - 1] = '\0';
	number = (unsigned long int)arg;

	if (arg < 0)
	{
		number = (unsigned long int)((-1) * arg);
		is_neg = 1;
	}
	while (number >= 1)
	{
		buffer[SIZE--] = (number % 10) + '0';
		number /= 10;
	}
	SIZE++;

	return (output_numbers(is_neg, SIZE, buffer, flag, wid, prec, size));
}

/**
 * print_binary - function that prints a number
 * @args: arguments passed
 * @buffer: array of chars
 * @flag: number of flag
 * @wid: width.
 * @prec: precision spec
 * @size: size
 * Return: required output
 */

int print_binary(va_list args, char buffer[], int flag, int wid, int prec,
		int size)
{
	unsigned int arg, max_int;
	unsigned int index, sum;
	unsigned int array[32];
	int count;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(prec);
	UNUSED(size);

	arg = va_arg(args, unsigned int);
	max_int = 2147483648; /* MAX_INT */
	array[0] = arg / max_int;

	for (index = 1; index < 32; index++)
	{
		max_int /= 2;
		array[index] = (arg / max_int) % 2;
	}
	for (index = 0, sum = 0, count = 0; index < 32; index++)
	{
		sum += array[index];
		if (sum || index == 31)
		{
			char last_element = '0' + array[index];

			write(1, &last_element, 1);
			count++;
		}
	}

	return (count);
}
