#include "lists.h"

/**
 * dlistint_len - function that returns the number of elements
 *		in a linked dlistint_t list.
 * @h: list to proocess
 * Return: total length
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t node_len = 0;

	while (h)
	{
		h = h->next;
		node_len++;
	}
	return (node_len);
}
