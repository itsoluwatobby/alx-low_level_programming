#include "main.h"

/**
 * print_pointer - function that prints the value of a pointer
 * @args: arguments passed
 * @buffer: array of chars
 * @flag: number of flag
 * @wid: width.
 * @prec: precision spec
 * @size: size
 * Return: required output
 */

int print_pointer(va_list args, char buffer[], int flag, int wid, int prec,
		int size)
{
	char extra_char = 0, padd = ' ';
	int index = BYTE_SIZE - 2, length = 2;
	int padd_start = 1; /* length = 2, for '0x' */
	unsigned long num_address;
	char hex_value[] = "0123456789abcdef";
	void *address = va_arg(args, void *);

	UNUSED(wid);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));
	buffer[BYTE_SIZE - 1] = '\0';
	UNUSED(prec);

	num_address = (unsigned long)address;
	while (num_address > 0)
	{
		buffer[index--] = hex_value[num_address % 16];
		num_address /= 16;
		length++;
	}
	if ((flag & ZERO) && !(flag & MINUS_SIGN))
		padd = '0';
	if (flag & PLUS_SIGN)
	{
		extra_char = '+';
		length++;
	}
	else if (flag & SPACE)
	{
		extra_char = ' ';
		length++;
	}
	index++;

	return (write_pointer(buffer, index, length, wid, flag, padd,
				extra_char, padd_start));
}

/**
 * print_non_printable - function that prints ascii codes in hexa
 *		of non printable chars
 * @args: arguments passed
 * @buffer: array of chars
 * @flag: number of flag
 * @wid: width.
 * @prec: precision spec
 * @size: size
 * Return: required output
 */

int print_non_printable(va_list args, char buffer[], int flag, int wid,
		int prec, int size)
{
	int index = 0, offset = 0;
	char *strings = va_arg(args, char *);
	char *null = "(null)";

	UNUSED(flag);
	UNUSED(wid);
	UNUSED(prec);
	UNUSED(size);

	if (strings == NULL)
		return (write(1, null, 6));
	while (strings[index] != '\0')
	{
		if (is_char(strings[index]))
			buffer[index + offset] = strings[index];
		else
			offset += append_hexa_code(strings[index], buffer,
					index + offset);
		index++;
	}
	buffer[index + offset] = '\0';

	return (write(1, buffer, index + offset));
}

/**
 * print_reversal - function that prints a string in reverse.
 * @args: arguments passed
 * @buffer: array of chars
 * @flag: number of flag
 * @wid: width.
 * @prec: precision spec
 * @size: size
 * Return: required output
 */

int print_reversal(va_list args, char buffer[], int flag, int wid, int prec,
		int size)
{
	char *strings;
	int index, count = 0, len;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(size);

	strings = va_arg(args, char *);

	if (strings == NULL)
	{
		UNUSED(prec);
		strings = ")Null(";
	}
	for (len = 0; strings[len]; len++)
		;

	for (index = len - 1; index >= 0; index--)
	{
		char element = strings[index];

		write(1, &element, 1);
		count++;
	}

	return (count);
}

/**
 * print_rot13 - function that prints a string in rot13 format.
 * @args: arguments passed
 * @buffer: array of chars
 * @flag: number of flag
 * @wid: width.
 * @prec: precision spec
 * @size: size
 * Return: required output
 */

int print_rot13(va_list args, char buffer[], int flag, int wid, int prec,
		int size)
{
	char x, *strings;
	unsigned int i, j;
	int count = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	strings = va_arg(args, char *);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(prec);
	UNUSED(size);

	if (strings == NULL)
		strings = "(AHYY)";
	for (i = 0; strings[i]; i++)
	{
		for (j = 0; input[j]; j++)
		{
			if (input[j] == strings[i])
			{
				x = output[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!input[j])
		{
			x = strings[i];
			write(1, &x, 1);
			count++;
		}
	}

	return (count);
}
