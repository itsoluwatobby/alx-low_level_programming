#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * delete_nodeint_at_index - function that deletes the node at index
 *			of a listint_t linked list.
 * @head: node in listint_t
 * @index: node index to be deleted
 * Return: address of n
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *previous = *head, *current = *head;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = current->next;
		free(current);
		current = NULL;
		return (1);
	}
	else
	{
		while (index != 1)
		{
			previous = current;
			current = current->next;
			index--;
		}
		previous->next = current->next;
		free(current);
		current = NULL;
	}

	return (1);
}
