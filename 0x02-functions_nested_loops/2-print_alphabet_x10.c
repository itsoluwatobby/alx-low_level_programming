#include <stdio.h>
/**
 * main - a function that prints 10 times the alphabet, in lowercase
 * Return: 0 (success)
*/

void print_alphabet_x10(char alph)
{
	putchar(alph);
}

int main(void)
{
	int n = 0;
	char i;

	while (n < 10)
	{
		for (i = 'a'; i <= 'z'; i++)
			print_alphabet_x10(i);
		putchar('\n');
		n++;
	}
	return (0);
}
