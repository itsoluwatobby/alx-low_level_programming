#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - function that frees a listint_t list.
 * @head: node in listint_t
 */

void free_listint2(listint_t **head)
{
	listint_t *buffer;

	if (head == NULL)
		return;

	while (*head)
	{
		buffer = (*head)->next;
		free(*head);
		*head = buffer;
	}
	head = NULL;
}
