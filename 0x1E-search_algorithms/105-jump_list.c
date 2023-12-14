#include "search_algos.h"
#include <math.h>

/**
 * jump_list - function that searches for a value in a sorted
 *		list of integers using the Jump search algorithm.
 * @list: list of integers passed as an arg
 * @size: original lenght of the array
 * @value: target to be searched
 *
 * Return: first index of the target if SUCCESS
 *	else (absent/NULL) -1
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, step_size;
	listint_t *node, *jump;

	if (list == NULL || list->n == NULL || size == 0)
		return (NULL);

	step = 0;
	step_size = sqrt(size);

	while (list->n != NULL)
	{
		printf("Index[%ld] = [%d]\n", list->index, list->n;
		list->next;
	}

	for (node = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		node = jump;
		for (step += step_size; jump->index < step; jump = jump->next)
			if (jump->index + 1 == size)
				break;
		printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jump->index);

	for (; node->index < jump->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n",
			node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n",
		node->index, node->n);

	return (node->n == value ? node : NULL);
}
