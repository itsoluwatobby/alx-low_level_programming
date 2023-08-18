#include "lists.h"

/**
 * insert_dnodeint_at_index -  function that inserts a new
 *		node at a given position.
 * @h: start
 * @idx: given position
 * @n: element at index
 * Return: address of new node Or NULL
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *copy = *h;
	unsigned int i;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL || *h == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = copy;
		*h = new;
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
