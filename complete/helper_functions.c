#include "main.h"

/**
 * is_char - function thats checks if a value is a char type
 * @c: given character
 * Return: on success (1), 0 otherwise
 */

int is_char(char c)
{
	if (c > 31 && c < 127)
		return (1);
	return (0);
}

/**
 * append_hexa_code - function that appends ascii in hexadecimal code
 * @buffer: array of characters.
 * @index: index.
 * @ascii_code: ASCII CODE.
 * Return: Always 3
 */

int append_hexa_code(char ascii_code, char buffer[], int index)
{
	char hex_value[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[index++] = '\\';
	buffer[index++] = 'x';
	buffer[index++] = hex_value[ascii_code / 16];
	buffer[index] = hex_value[ascii_code % 16];

	return (3);
}

/**
 * is_digit - function that checks if a char is a digit
 * @c: char
 * Return: on success (1), 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * convert_int_size - funct that casts a number to its size
 * @nums: given number.
 * @size: size of data type to be casted.
 * Return: nums
 */
long int convert_int_size(long int nums, int size)
{
	if (size == LONG)
		return (nums);
	else if (size == SHORT)
		return ((short)nums);

	return ((int)nums);
}

/**
 * convert_unsigned_size - Casts a number to the specified size
 * @nums: given number.
 * @size: size of data type to be casted.
 * Return: nums
 */

long int convert_unsigned_size(unsigned long int nums, int size)
{
		if (size == LONG)
			return (nums);
		else if (size == SHORT)
			return ((unsigned short)nums);

		return ((unsigned int)nums);
}

