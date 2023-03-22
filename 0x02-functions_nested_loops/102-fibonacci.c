#include <stdio.h>
/**
 * main -  program that prints the first 50 Fibonacci numbers
 * Return: 0 (success)
 */
int main(void)
{
	int k = 0;
	int x = 1;
	int n = 1;
	unsigned long sum;

	while (n <= 50)
	{
		sum = k + x;
		printf("%lu", sum);

		k = x;
		x = sum;

		if (n <= 50)
			printf(", ");
		n++;
	}
	return (0);
}
