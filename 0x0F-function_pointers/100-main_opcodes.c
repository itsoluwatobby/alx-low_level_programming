#include <stdio.h>
#include <stdlib.h>

/**
 * main - function that prints opcodes.
 * @argc: number of arguments passed.
 * @argv: array of pointers to arguments passed.
 *
 * Return: on success (0).
 */
int main(int argc, char *argv[])
{
	int byte, i;
	int (*pointer_address)(int, char **) = main;
	unsigned char opcode;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	byte = atoi(argv[1]);

	if (byte < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < byte; i++)
	{
		opcode = *(unsigned char *)pointer_address;
		printf("%.2x", opcode);

		if (i == byte - 1)
			continue;
		printf(" ");

		pointer_address++;
	}

	printf("\n");

	return (0);
}
