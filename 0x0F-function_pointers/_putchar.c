#include <unistd.h>

/**
 * _putchar - function that prints a character
 * @c: character to print
 * Return: on success (1), else (0)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
