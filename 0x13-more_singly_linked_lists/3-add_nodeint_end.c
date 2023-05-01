#include "lists.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * add_nodeint_end - function that adds a new node at the end
 *		of a listint_t list.
 * @head: node to add
 * @n: element in listint_t
 * Return: each node address
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *tail;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		printf("Error\n");
		return (NULL);
	}

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		tail = *head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = new;
	}

	return (*head);
}
