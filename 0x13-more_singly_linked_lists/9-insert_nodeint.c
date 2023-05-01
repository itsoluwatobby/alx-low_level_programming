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
	while (idx != 1)
	{
		copy = copy->next;
		idx--;
	}
	if (copy == NULL)
		return (NULL);

	new->next = copy->next;
	copy->next = new;

	return (copy);
}
