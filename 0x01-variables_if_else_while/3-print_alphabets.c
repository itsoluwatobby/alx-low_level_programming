#include <stdio.h>
#include <ctype.h>
/**
 * main - program that prints the alphabet in lowercase and then in uppercase
 * Return: 0 (success)
*/
int main(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
		putchar(i);
	for (i = 'a'; i <= 'z'; i++)
		putchar(toupper(i));
	putchar('\n');
	return (0);
}
