#include "main.h"

/**
 * append_text_to_file - function that appends text at the end of a file
 * @filename: name of file
 * @text_content: content to write to file
 * Return: onsuccess (1), else (-1)
*/

int append_text_to_file(const char *filename, char *text_content)
{
	int view, wt, index = 0;

	if (!filename)
		return (-1);
	if (text_content)
	{
		while (text_content[index])
			index++;
	}
	view = open(filename, O_WRONLY | O_APPEND);
	wt = write(view, text_content, index);
	if (view == -1 || wt == -1)
		return (-1);
	close(view);
	return (1);
}
