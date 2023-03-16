#include <stdio.h>
/**
 * main - A program that prints the size of various data types
 * Return: 0 (success)
*/
int main(void)
{
	char a;
	int b;
	long int c;
	long long int d;
	float f;

printf("Size of a char: %lu byte(s)", (unsigned long)sizeof(a));
printf("\nSize of a int: %lu byte(s)", (unsigned long)sizeof(b));
printf("\nSize of a long int: %lu byte(s)", (unsigned long)sizeof(c));
printf("\nSize of a long long int: %lu byte(s)", (unsigned long)sizeof(d));
printf("\nSize of a float: %lu byte(s)", (unsigned long)sizeof(f));
return (0);
}
