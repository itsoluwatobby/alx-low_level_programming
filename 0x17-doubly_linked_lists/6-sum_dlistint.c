#include "lists.h"

/**
 * sum_dlistint - function that returns the sum of all the
 *		data (n) of a dlistint_t linked list.
 * @head: start of list
 * Return: sum else 0
 */

int sum_dlistint(dlistint_t *head)
{
	int total = 0;

	if (head == NULL)
		return (0);
	while (head)
	{
		total += head->n;
		head = head->next;
	}
	return (total);
}
