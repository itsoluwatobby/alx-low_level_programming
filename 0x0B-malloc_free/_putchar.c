#include <unistd.h>

/**
 * _putchar - prints out a specified character
 * @c: character to be printed
 * Return: on suceess(0)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
