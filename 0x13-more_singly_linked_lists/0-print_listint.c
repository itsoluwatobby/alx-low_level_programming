#include "lists.h"
#include <stdio.h>
#include <stddef.h>

/**
 * print_listint - function that prints all the elements of a listint_t list.
 * @h: element of listint_t
 * Return: number of element
 */

size_t print_listint(const listint_t *h)
{
	size_t node_len = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		node_len++;
	}
	return (node_len);
}
