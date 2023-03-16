#include <stdio.h>
/**
 * main - A program that prints the size of various data types
 * Return: 0 (success)
*/
int main(void)
{
	printf("Size of a char: %d byte(s)", sizeof(char));
	printf("\nSize of a int: %d bytes(s)", sizeof(int));
	printf("\nSize of a long int: %d bytes(s)", sizeof(long int));
	printf("\nSize of a long long int: %d bytes(s)", sizeof(long long int));
	printf("\nSize of a float: %d bytes(s)", sizeof(float));
	return (0);
}
