#include <stdio.h>
/**
 * main -  program that prints the first 50 Fibonacci numbers
 * Return: 0 (success)
 */
int main(void)
{
	unsigned int fib1 = 0;
	unsigned int fib2 = 1;
	int n;
	unsigned int sum;

	for (n = 0; n <= 50; n++)
	{
		sum = (fib1 + fib2);
		printf("%u", sum);

		fib1 = fib2;
		fib2 = sum;

		if (n <= 50)
			printf(", ");
	}
	return (0);
}
