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
	dlistint_t *curr = *head;

	if (*head == NULL)
		return (-1);

	for (; index != 0; index--)
	{
		if (curr == NULL)
			return (-1);
		curr = curr->next;
	}

	if (curr == *head)
	{
		*head = curr->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		curr->prev->next = curr->next;
		if (curr->next != NULL)
			curr->next->prev = curr->prev;
	}
	free(curr);

	return (1);
}
