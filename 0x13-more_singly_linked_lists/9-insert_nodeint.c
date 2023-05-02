#include "lists.h"
#include <stdlib.h>

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
	unsigned int i;

	new = malloc(sizeof(listint_t));
	if (new == NULL || *head == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = copy;
		*head = new;
		return (new);
	}
	for (i = 0; copy && i < idx; i++)
	{
		if (i == (idx - 1))
		{
			new->next = copy->next;
			copy->next = new;
			return (new);
		}
		else
			copy = copy->next;
	}
	return (NULL);
}
