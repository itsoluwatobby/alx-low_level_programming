#include "main.h"

/**
 * is_divided - function that checks number is divisible
 * @num: integer to check
 * @x: divisor
 * Return: divisible(0), else (1);
 */

int is_divided(int num, int x)
{
	if (num % x == 0)
		return (0);

	if (x == num / 2)
		return (1);

	return (is_divided(num, x + 1));
}

/**
 * is_prime_number - function that returns 1 if the
 *	input integer is a prime number, otherwise return 0.
 * @n: integer given
 * Return: prime of n;
 */

int is_prime_number(int n)
{
	int x = 2;

	if (n <= 1)
		return (0);

	if (n >= 2 && n <= 3)
		return (1);

	return (is_divided(n, x));
}
