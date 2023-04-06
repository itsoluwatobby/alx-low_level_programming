#include "main.h"
#include <ctype.h>
/**
 * _isupper - function that checks for uppercase character.
 * @c: value to be checked
 *
 * Return: on success 1, on error 0
 */
int _isupper(int c)
{
	if (isupper(c))
		return (1);
	else
		return (0);
}
