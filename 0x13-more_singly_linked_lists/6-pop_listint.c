#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pop_listint - function that deletes the head node of a listint_t
 *		linked list, and returns the head node’s data (n).
 * @head: node in listint_t
 * Return: integer at node
 */

int pop_listint(listint_t **head)
{
	listint_t *buffer;
	int n;

	if (*head == NULL)
		return (0);

	buffer = *head;
	n = (*head)->n;
	*head = (*head)->next;

	free(buffer);

	return (n);
}
