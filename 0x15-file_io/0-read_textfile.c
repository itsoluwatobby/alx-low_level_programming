#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - function that reads a text file and prints
 *		it to the POSIX standard output.
 * @filename: name of the file
 * @letters: number of letters in file
 * Return: number of letters in file
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t rd, wt, fd;
	char *buffer;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(letters * sizeof(char));
	rd = read(fd, buffer, letters);

	wt = write(STDOUT_FILENO, buffer, rd);

	free(buffer);
	close(fd);
	return (wt);
}
