#include "main.h"
#include <stdlib.h>

/**
 * argstostr - function that concatenates all the
 *		arguments of your program.
 * @ac: arguments passed to the program.
 * @av: pointers to the arguments.
 *
 * Return: pointer to the new string.
 */
char *argstostr(int ac, char **av)
{
	char *new_str;
	int args, byte, i, size = ac;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (args = 0; args < ac; args++)
	{
		for (byte = 0; av[args][byte]; byte++)
			size++;
	}

	new_str = malloc(sizeof(char) * size + 1);

	if (new_str == NULL)
		return (NULL);

	i = 0;

	for (args = 0; args < ac; args++)
	{
		for (byte = 0; av[args][byte]; byte++)
			new_str[i++] = av[args][byte];

		new_str[i++] = '\n';
	}

	new_str[size] = '\0';

	return (new_str);
}
