#include <stdio.h>

/**
 * main - function that prints the number of arguments
 *	passed into it.
 * @argc: argument count
 * @argv: arguments
 * Return: on success(0), else(1)
 */

int main(int argc, char __attribute__((__unused__)) *argv[])
{
	printf("%i\n", argc - 1);
	return (0);
}
