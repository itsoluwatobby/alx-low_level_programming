#include <stdio.h>
/**
 * main - Write a program that finds and prints the
 *	largest prime factor of a number
 * Return: on success 1, on error 0
 */
int main(void)
{
	long prime = 612852475143;
	long div;

	while (div < (prime / 2))
	{
		if ((prime % 2) == 0)
		{
			prime /= 2;
			continue;
		}

		for (div = 3; div < (prime / 2); div += 2)
		{
			if ((prime % div) == 0)
				prime /= div;
		}
	}

	printf("%ld\n", prime);

	return (0);
}
