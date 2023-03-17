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
		/*int e = i + j;*/

		for (j = 0; j < 100; j++)
		{
			int a = i / 10;
			int b = i % 10;
			int c = j / 10;
			int d = j % 10;

			if ((a + b) == (c + d) && ((a + b) + (c + d) != 2))
				continue;
			else if ((a + b) > (c + d))
				continue;

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
