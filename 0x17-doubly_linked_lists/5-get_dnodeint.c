#include "lists.h"

/**
 * get_dnodeint_at_index - function that returns the nth node
 *		of a dlistint_t linked list.
 * @head: start
 * @index: position of node
 * Return: node or Null
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int position = 0;

	if (head == NULL)
		return (NULL);

	while (head)
	{
		if (position == index)
			return (head);
		head = head->next;
		position++;
	}

	return (NULL);
}
