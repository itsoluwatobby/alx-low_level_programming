#include <stdio.h>
#include <stdlib.h>

/**
 * main - function that multiplies two numbers
 * @argc: argument count
 * @argv: arguments
 * Return: on success(0), else(1)
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	int result = (atoi(argv[1])) * (atoi(argv[2]));

	printf("%d\n", result);

	return (0);
}
