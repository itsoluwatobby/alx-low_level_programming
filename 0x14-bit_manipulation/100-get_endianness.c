#include "main.h"

/**
 * get_endianness - function that checks the endianness.
 * Return: 0 if big endian, else 1 for little
 */

int get_endianness(void)
{
	unsigned int c = 1;
	char *str = (char *) &c;

	return (*str);
}
