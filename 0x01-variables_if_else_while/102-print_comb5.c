#include <stdio.h>
/**
 * main - program that prints possible combinations of two two-digit numbers
 * Return: 0 (success)
*/
int main(void)
{
	int i;
	int j;

	for (i = 0; i < 100; i++)
	{
		for (j = i; j < 100; j++)
		{
			int a = i / 10;
			int b = i % 10;
			int c = j / 10;
			int d = j % 10;

			putchar('0' + a);
			putchar('0' + b);
			putchar(' ');
			putchar('0' + c);
			putchar('0' + d);
			putchar(',');

			if (i != 99 || j != 99)
			{
				putchar(' ');
			}
		}
	}
	return (0);
}
