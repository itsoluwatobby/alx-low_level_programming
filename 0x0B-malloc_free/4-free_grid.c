#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Function that frees a 2-dimensional array.
 * @grid: array of integers to be freed.
 * @height: height of grid.
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
