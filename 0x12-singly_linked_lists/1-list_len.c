#include "lists.h"
#include <stdio.h>

/**
 * list_len - function that returns the number of elements in
 *		a linked list_t list.
 * @h: given list_t
 * Return: length of list
 */

size_t list_len(const list_t *h)
{
	size_t length = 0;

	while (h)
	{
		length++;
		h = h->next;
	}
	return (length);
}
