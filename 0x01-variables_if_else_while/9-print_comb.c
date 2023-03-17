#include <stdio.h>
/**
 * main - program that prints all possible combinations of single-digit numbers
 * Return: 0 (success)
*/
int main(void)
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		if (i < 9)
		{
			putchar(i + '0');
			putchar(',');
		}
		else
		{
			putchar(i + '0');
		}
		putchar(' ');
	}

	return (0);
}
