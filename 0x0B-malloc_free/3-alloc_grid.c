#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - function that returns a pointer to a
 *		2-dimensional array of integers.
 * @width: number of columns.
 * @height: number of rows.
 *
 * Return: columns <= 0, rows <= 0, or fails - NULL.
 *         else - a pointer to the 2-dimensional array.
 */
int **alloc_grid(int width, int height)
{
	int **array;
	int row_index, col_index;

	if (width <= 0 || height <= 0)
		return (NULL);

	array = malloc(sizeof(int *) * height);

	if (array == NULL)
		return (NULL);

	for (row_index = 0; row_index < height; row_index++)
	{
		array[row_index] = malloc(sizeof(int) * width);

		if (array[row_index] == NULL)
		{
			for (; row_index >= 0; row_index--)
				free(array[row_index]);

			free(array);
			return (NULL);
		}
	}

	for (row_index = 0; row_index < height; row_index++)
	{
		for (col_index = 0; col_index < width; col_index++)
			array[row_index][col_index] = 0;
	}

	return (array);
}
