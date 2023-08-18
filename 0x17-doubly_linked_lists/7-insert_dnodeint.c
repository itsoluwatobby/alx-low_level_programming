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

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (; idx != 1; idx--)
	{
		copy = copy->next;
		if (copy == NULL)
			return (NULL);
	}

	if (copy->next == NULL)
		return (add_dnodeint_end(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = copy;
	new->next = copy->next;
	copy->next->prev = new;
	copy->next = new;

	return (new);
}
