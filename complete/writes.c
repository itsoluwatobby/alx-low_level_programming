#include "main.h"

/**
 * handles_write_char - funtion that prints a string of char
 * @c: character.
 * @buffer: array to handle print
 * @flag: number flags.
 * @wid: width.
 * @prec: precision
 * @size: size
 * Return: required output.
 */

int handles_write_char(char c, char buffer[], int flag, int wid, int prec,
		int size)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	char padd = ' ';

	UNUSED(prec);
	UNUSED(size);

	if (flag & ZERO)
		padd = '0';
	buffer[i++] = c;
	buffer[i] = '\0';

	if (wid > 1)
	{
		buffer[BYTE_SIZE - 1] = '\0';

		for (i = 0; i < wid - 1; i++)
			buffer[BYTE_SIZE - i - 2] = padd;
		if (flag & MINUS_SIGN)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BYTE_SIZE - i - 1],
						wid - 1));
		else
			return (write(1, &buffer[BYTE_SIZE - i - 1],
						wid - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * output_numbers - funtions that prints a string
 * @is_neg: first arg
 * @ind: second param.
 * @buffer: array to handle print
 * @flag:  numbers flags
 * @wid: width.
 * @prec: precision
 * @size: size
 * Return: required output.
 */

int output_numbers(int is_neg, int ind, char buffer[], int flag, int wid,
		int prec, int size)
{
	int len = BYTE_SIZE - ind - 1;
	char padd = ' ', extra_char = 0;

	UNUSED(size);

	if ((flag & ZERO) && !(flag & MINUS_SIGN))
		padd = '0';
	if (is_neg)
		extra_char = '-';
	else if (flag & PLUS_SIGN)
		extra_char = '+';
	else if (flag & SPACE)
		extra_char = ' ';

	return (write_num(ind, buffer, flag, wid, prec, len, padd, extra_char));
}

/**
 * write_num - function that write a number using a bufffer
 * @ind: start index on the buffer
 * @buffer: Buffer
 * @flag: flag
 * @wid: width
 * @prec: precision
 * @len: length
 * @padd: padding char
 * @extra_char: extra char
 * Return: required output.
 */

int write_num(int ind, char buffer[], int flag, int wid, int prec,
		int len, char padd, char extra_char)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BYTE_SIZE - 2 &&
			buffer[ind] == '0' && wid == 0)
		return (0); /* printf(".0d", 0)  no char will be printed */
	if (prec == 0 && ind == BYTE_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /*width is displayed with padding ' '*/
	if (prec > 0 && prec < len)
		padd = ' ';
	while (prec > len)
		buffer[--ind] = '0', len++;
	if (extra_char != 0)
		len++;
	if (wid > len)
	{
		for (i = 1; i < wid - len + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flag & MINUS_SIGN && padd == ' ')/*extra char to buffer left*/
		{
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[ind], len) + write(1, &buffer[1], i - 1));
		}
		else if (!(flag & MINUS_SIGN) && padd == ' ')/*extra char to buffer left */
		{
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], len));
		}
		else if (!(flag & MINUS_SIGN) && padd == '0')/*extra char to padd left */
		{
			if (extra_char)
				buffer[--padd_start] = extra_char;
			return (write(1, &buffer[padd_start], i - padd_start) + write(1,
						&buffer[ind], len - (1 - padd_start)));
		}
	}
	if (extra_char)
		buffer[--ind] = extra_char;
	return (write(1, &buffer[ind], len));
}

/**
 * write_unsigned_val - function that writes an unsigned number
 * @is_neg: first param
 * @ind: starts of the buffer
 * @buffer: Array of chars
 * @flag: Flags
 * @wid: Width
 * @prec: precision
 * @size: size
 * Return: required output
 */

int write_unsigned_val(int is_neg, int ind, char buffer[], int flag,
		int wid, int prec, int size)
{/* The number is stored at the bufer's right and starts at position i */
	int len = BYTE_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_neg);
	UNUSED(size);

	if (prec == 0 && ind == BYTE_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec > 0 && prec < len)
		padd = ' ';
	while (prec > len)
	{
		buffer[--ind] = '0';
		len++;
	}
	if ((flag & ZERO) && !(flag & MINUS_SIGN))
		padd = '0';
	if (wid > len)
	{
		for (i = 0; i < wid - len; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flag & MINUS_SIGN) /*extra char to buffer left [buffer>padd]*/
		{
			return (write(1, &buffer[ind], len) +
					write(1, &buffer[0], i));
		}
		else /*extra char to padding left [padd>buffer]*/
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], len));
	}
	return (write(1, &buffer[ind], len));
}

/**
 * write_pointer - function that writes a memory address
 * @buffer: Arrays of characters
 * @ind: start of buffer
 * @len: Length
 * @wid: Width
 * @flag: Flag
 * @padd: Char representing the padding
 * @extra_char: extra character
 * @padd_start: Index at which padding should start
 * Return: required output.
 */

int write_pointer(char buffer[], int ind, int len, int wid, int flag,
		char padd, char extra_char, int padd_start)
{
	int i;

	if (wid > len)
	{
		for (i = 3; i < wid - len + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flag & MINUS_SIGN && padd == ' ')/*extra char to buffer left */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[ind], len) +
					write(1, &buffer[3], i - 3));
		}
		else if (!(flag & MINUS_SIGN) && padd == ' ')/*char to buffer left*/
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[3], i - 3) +
					write(1, &buffer[ind], len));
		}
		else if (!(flag & MINUS_SIGN) && padd == '0')/*char to padd left*/
		{
			if (extra_char)
				buffer[--padd_start] = extra_char;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) + write(1,
						&buffer[ind], len - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_char)
		buffer[--ind] = extra_char;
	return (write(1, &buffer[ind], BYTE_SIZE - ind - 1));
}
