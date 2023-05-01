#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * sum_listint - function that returns the sum of all the data
 *		(n) of a listint_t linked list.
 * @head: node in listint_t
 * Return: node at index
 */

int sum_listint(listint_t *head)
{
	unsigned int n = 0;

	if (head == NULL)
		return (0);

	while (head)
	{
		n += head->n;
		head = head->next;
	}
	return (n);
}
