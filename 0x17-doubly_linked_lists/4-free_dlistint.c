#include "lists.h"

/**
 * free_dlistint - function that frees a dlistint_t list.
 * @head: head of list
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *buf;

	while (head)
	{
		buf = head->next;
		free(head);
		head = buf;
	}
}
