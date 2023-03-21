#include "main.h"
/**
 * print_last_digit - function that prints the last digit of a number
 * @n: character to be printed
 * Return: x
 */
int print_last_digit(int n)
{
	int x = n % 10;

	if (x < 0)
		x = -x;
	_putchar(x + '0');
	return (x);
