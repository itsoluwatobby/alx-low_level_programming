#include <stdio.h>
/**
 * main -  a function that prints the alphabet, in lowercase
 * Return: 0 (success)
*/

void print_alphabet(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
	{
		putchar(i);
	}
	putchar('\n');
}
