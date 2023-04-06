#include <stdio.h>

/**
 * main - function that prints the number of arguments
 *	it receives.
 * @argc: argument count
 * @argv: arguments
 * Return: on success(0), else(1)
 */

int main(int argc, char *argv[])
{
	int i = 0;

	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}
