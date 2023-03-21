#include "main.h"
/**
 * print_alphabet_x10 - prints 10 times the alphabet in lowercase
*/

void print_alphabet_x10(void)
{
	int n = 0;
	char i;

	while (n < 10)
	{
		for (i = 'a'; i <= 'z'; i++)
			_putchar(i);
		_putchar('\n');
		n++;
	}
}
