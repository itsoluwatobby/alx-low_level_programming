#!/usr/bin/python3
'''
A function for grid island_perimeter
'''


def island_perimeter(grid):
    '''
    Returns perimeter of the island described in a grid

    The grid represents water by 0 and land by 1.

    Args:
        grid (list): A list of lists of integers
    '''
    grid_width = len(grid[0])
    grid_height = len(grid)
    edges = 0
    perimeter = 0

    for i in range(grid_height):
        for j in range(grid_width):
            if grid[i][j] == 1:
                perimeter += 1
                if (j > 0 and grid[i][j - 1] == 1):
                    edges += 1
                if (i > 0 and grid[i - 1][j] == 1):
                    edges += 1
    return perimeter * 4 - edges * 2
