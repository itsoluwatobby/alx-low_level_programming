#include "main.h"
#include <ctype.h>

/**
 * _isdigit - function that checks for a digit (0 through 9)
 * @c: value to be checked
 * Return: on success 1, on error 0
 */
int _isdigit(int c)
{
	if (isdigit(c))
		return (1);
	else
		return (0);
}
