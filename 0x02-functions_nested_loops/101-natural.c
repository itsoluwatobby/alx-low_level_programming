#include <stdio.h>
/**
 * main - a program that computes and prints the sum of
 *	all the multiples of 3 or 5 below 1024 (excluded)
 * @i: multiples of the given number
 * @sum: computes the sum of all the multiples 
 *Return: 0 (success)
 */
int main(void)
{
	int i;
	int sum = 0;

	for (i = 0; i < 1024; i++)
	{
		if ((i % 3) == 0 || (i % 5) == 0)
			sum += i;
	}

	printf("%d\n", sum);
	return (0);
}
