#include <stdio.h>
/**
 * main - program that finds and prints the sum of the even-valued terms
 * Return: 0 (success)
 */
int main(void)
{
	unsigned int fib1 = 0;
	unsigned int fib2 = 1;
	unsigned int sum;

	while (1)
	{
		sum = fib1 + fib2;
		if (sum > 4000000)
			break;

		if ((sum % 2) == 0)
			printf("%u", sum);

		if ((sum % 2 == 0) && sum < 4000000)
			printf(", ");

		fib1 = fib2;
		fib2 = sum;
	}

	return (0);
}
