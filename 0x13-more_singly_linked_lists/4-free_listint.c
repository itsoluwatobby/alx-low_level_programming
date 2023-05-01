#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - function that frees a listint_t list.
 * @head: node in listint_t
 */

void free_listint(listint_t *head)
{
	listint_t *buffer;

	while (head)
	{
		buffer = head->next;
		free(head);
		head = buffer;
	}
}
