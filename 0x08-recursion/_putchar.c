#include <unistd.h>
/**
 * _putchar - prints out a character
 * @c: character to be returned
 * Return: on success(0), on error(1)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
