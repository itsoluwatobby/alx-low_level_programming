#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_nodeint_at_index - function that inserts a new node at a
 *			given position.
 * @head: node in listint_t
 * @idx: node index
 * @n: given node for insertion
 * Return: address of n
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int pos;
	listint_t *new, *copy = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		printf("Error\n");
		return (0);
	}

	new->n = n;

	for (pos = 0; pos < (idx - 1); pos++)
	{
		if (*head == NULL || (*head)->next == NULL)
			return (NULL);

		copy = copy->next;
	}
	new->next = copy->next;
	copy->next = new;

	return (new);
}
