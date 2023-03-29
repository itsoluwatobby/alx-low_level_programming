#include "main.h"
#include <stdio.h>

/**
 * reverse_array - function that reverses the content of
 *			an array of integers.
 * @a: an array of integers
 * @n: the number of elements to swap.
 */

void reverse_array(int *a, int n)
{
	int i;

	for (i = (n - 1); i >= 0; i--)
	{
		if (i != 0)
			printf("%d, ", a[i]);
		else
			printf("%d", a[i]);
	}
	printf("\n");
}
