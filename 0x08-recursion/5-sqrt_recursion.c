#include "main.h"

/**
 * find_root - finds the natural root of a number
 * @i: number to find root of
 * @j: root to be tested
 * Return: if natural root (square root), else (-1)
 */

int find_root(int i, int j)
{
	if ((j * j) == i)
		return (j);

	if (j == i / 2)
		return (-1);

	return (find_root(i, j + 1));
}

/**
 * _sqrt_recursion - function that returns the natural
 *			square root of a number.
 * @n: given integer
 * Return: root n
 */

int _sqrt_recursion(int n)
{
	int j = 0;

	if (n < 0)
		return (-1);

	if (n == 1)
		return (1);

	return (find_root(n, j));
}
