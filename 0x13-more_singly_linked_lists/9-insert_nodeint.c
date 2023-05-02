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
	listint_t *new, *copy = *head;

	if (*head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	if (idx == 0)
	{
		new->next = copy;
		*head = new;
		return (new);
	}
	while (idx != 1)
	{
		if (copy == NULL || copy->next == NULL)
			return (NULL);
		copy = copy->next;
		idx--;
	}

	new->next = copy->next;
	copy->next = new;

	return (copy);
}
