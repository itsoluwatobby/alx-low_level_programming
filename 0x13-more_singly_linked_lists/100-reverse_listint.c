#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * reverse_listint - function that reverses a of a listint_t linked list.
 * @head: node in listint_t
 * Return: listint_t reversal
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous, *current;

	if (*head == NULL)
		return (NULL);

	previous = NULL;
	while ((*head)->next != NULL)
	{
		current = (*head)->next;
		(*head)->next = previous;
		previous = *head;
		*head = current;
	}
	(*head)->next = previous;

	return (*head);
}
