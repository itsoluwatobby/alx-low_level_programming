#include "main.h"
#include <string.h>
#include <math.h>

/**
 * puts_half - function that prints half of a string
 * @str: string to print
 */

void puts_half(char *str)
{
	long int len =  strlen(str);
	int i;

	if ((len % 2) == 0)
	{
		for (i = len / 2; i < len; i++)
			_putchar(str[i]);
	}
	else
	{
		int div = ceil(len / 2);

		for (i = div; i < len; i++)
			_putchar(str[i]);
	}	
	_putchar('\n');
}
