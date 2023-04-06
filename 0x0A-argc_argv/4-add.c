#include <stdio.h>
#include <stdlib.h>

/**
 * main - function that adds positive numbers
 * @argc: argument count
 * @argv: arguments
 * Return: on success(0), else(1)
 */

int main(int argc, char *argv[])
{
	int i = 1, number, sum = 0;

	if (argc == 0)
		printf("0");

	while (i < argc)
	{
		for (number = 0; argv[i][number]; number++)
		{
			if (argv[i][number] < '0' || argv[i][number] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}

		sum += atoi(argv[i]);
		i++;
	}

	printf("%d\n", sum);

	return (0);
}
