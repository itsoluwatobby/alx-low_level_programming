#include "lists.h"
#include <stddef.h>
#include <stdio.h>

/**
 * listint_len - function that returns the number of elements
 *		in a linked listint_t list.
 * @h: element in listint_t
 * Return: the number of elements in listint_t
 */

size_t listint_len(const listint_t *h)
{
	size_t node_len = 0;

	while (h)
	{
		h = h->next;
		node_len++;
	}
	return (node_len);
}
