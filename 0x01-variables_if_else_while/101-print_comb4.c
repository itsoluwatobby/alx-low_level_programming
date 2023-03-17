#include <stdio.h>
/**
 * main -  program that prints all possible combinations of three digits
 * Return: 0 (success)
 */
int main(void)
{
	int i;
	int j;
	int k;

	for (i = 0; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			for (k = 2; k < 10; k++)
			{
				if (i < j && j < k && i != j)
				{
					putchar(i + '0');
					putchar(j + '0');
					putchar(k + '0');
					if (i + j + k != 24)
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
