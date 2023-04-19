#include "3-calc.h"

/**
 * op_add - function that adds two integers
 * @a: first integer
 * @b: second integer
 * Return: sum of a, b
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - function that subtracts two integers
 * @a: first integer
 * @b: second integer
 * Return: subtraction of a, b
 */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - function that multiplies two integers
 * @a: first integer
 * @b: second integer
 * Return: multiplication of a, b
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - function that divides two integers
 * @a: first integer
 * @b: second integer
 * Return: division of a, b
 */

int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - function that returns the remainder of the
 *		division of two integers
 * @a: first integer
 * @b: second integer
 * Return: remainder of a / b
 */

int op_mod(int a, int b)
{
	return (a % b);
}
