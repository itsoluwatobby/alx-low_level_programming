#include "lists.h"
#include <stdio.h>
#include <stddef.h>

/**
 * print_list - function that prints all the elements of a list_t list.
 * @h: given parameter
 * Return: a list of list_t
 */

size_t print_list(const list_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		nodes++;
		h = h->next;
	}
	return (nodes);
}
