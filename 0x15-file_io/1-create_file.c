#include "main.h"

/**
 * create_file - function that creates a file
 * @filename: name of file
 * @text_content: content to write to file
 * Return: onsuccess (1), else (-1)
*/

int create_file(const char *filename, char *text_content)
{
	int fileDesc, wt, index = 0;

	if (filename == NULL)
		return (-1);
	if (text_content)
	{
		while (text_content[index])
			index++;
	}
	fileDesc = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wt = write(fileDesc, text_content, index);
	if (fileDesc == -1 || wt == -1)
		return (-1);
	close(fileDesc);
	return (1);
}
