#include "main.h"
/**
 * _abs - function that computes the absolute value of an integer
 * @n: The integer to be computed
 * Return: 1 if is absolute value, else -1
 */
int _abs(int n)
{
	if (n > 0)
	{
		_putchar(n);
		return (1);
	}
	else
	{
		return (-1);
	}
}
