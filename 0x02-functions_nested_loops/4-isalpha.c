#include "main.h"
/**
 * _isalpha - function that checks for alphabetic character
 * @c: The character to be checked
 * Return: 1 if c is lowercase, else 0;
 */
int _isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
