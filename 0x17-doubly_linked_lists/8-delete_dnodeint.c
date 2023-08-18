#include "lists.h"

/**
 * delete_dnodeint_at_index - function that deletes the
 *		node at index index of a dlistint_t linked list.
 * @head: start
 * @index: position of node
 * Return: 1 onsuccess else -1
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *prev = NULL, *curr = *head;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = curr->next;
		free(curr);
		curr = NULL;
		return (1);
	}
	while (index != 1)
	{
		if (!curr || !(curr->next))
			return (-1);
		curr = curr->next;
		index--;
	}
	prev = curr->next;
	curr->next = prev->next;
	free(prev);

	return (1);
}
