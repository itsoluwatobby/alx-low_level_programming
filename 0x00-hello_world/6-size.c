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

printf("Size of a char: %d byte(s)", sizeof(a));
printf("\nSize of an int: %d byte(s)", sizeof(b));
printf("\nSize of a long int: %d byte(s)", sizeof(c));
printf("\nSize of a long long int: %d byte(s)", sizeof(d));
printf("\nSize of a float: %d byte(s)\n", sizeof(f));
return (0);
}
