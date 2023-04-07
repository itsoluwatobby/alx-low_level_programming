#include <stdio.h>
#include <stdlib.h>

/**
 * main - function that multiplies two numbers
 * @argc: argument count
 * @argv: arguments
 * Return: on success(0), else(1)
 */

int main(int argc, char *argv[])
{
	int result;

	if (argc < 2)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		result = (atoi(argv[1])) * (atoi(argv[2]));
		printf("%d\n", result);
	}

	return (0);
}
