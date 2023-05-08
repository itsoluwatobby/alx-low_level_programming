#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *storage(char *filename);
void exit_current_file(int fileDesc);

/**
 * storage - function that allocates a buffer size of 1024
 * @filename: location to store the file
 * Return: pointer to new file
 */

char *storage(char *filename)
{
	char *store;

	store = malloc(1024 * sizeof(char));
	if (!store)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (store);
}

/**
 * exit_current_file - function that closes the file descriptors
 * @fileDesc: given file descriptors
 */

void exit_current_file(int fileDesc)
{
	int exit_file;

	exit_file = close(fileDesc);
	if (exit_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileDesc);
		exit(100);
	}
}

/**
 * main - function that copies a file to another file
 * @argc: count of arguments parsed in
 * @argv: given arguments
 *
 * Desc: exit code 97 if count is wrong, if file is null exit with 98
 *	if file creation err: exit with 99, else unable to close: exit with 100
 * Return: onsucess (0), else (1)
 */

int main(int argc, char *argv[])
{
	int file_from, file_to, rd, wt;
	char *store;

	if (argc < 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	store = storage(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	rd = read(file_from, store, 1024);

	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {

		if (file_from == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(store);
			exit(98);
		}
		wt = write(file_to, store, rd);
		if (file_to == -1 || wt == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(store);
			exit(99);
		}
		rd = read(file_from, store, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);
	} while (rd > 0);

	free(store);
	exit_current_file(file_from);
	exit_current_file(file_to);
	return (0);
}
