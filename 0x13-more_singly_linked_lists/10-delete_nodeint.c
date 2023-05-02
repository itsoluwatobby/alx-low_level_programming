#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - function that deletes the node at index
 *			of a listint_t linked list.
 * @head: node in listint_t
 * @index: node index to be deleted
 * Return: address of n
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *previous = NULL, *current = *head;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = current->next;
		free(current);
		current = NULL;
		return (1);
	}
	while (index != 1)
	{
		if (!current || !(current->next))
			return (-1);
		current = current->next;
		index--;
	}
	previous = current->next;
	current->next = previous->next;
	free(previous);

	return (1);
}
