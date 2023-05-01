#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * get_nodeint_at_index - function that returns the nth node of
 *			a listint_t linked list.
 * @head: node in listint_t
 * @index: node index
 * Return: node at index
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int n = 0;
	listint_t *res;

	if (head == NULL)
		return (NULL);

	res = malloc(sizeof(listint_t));
	if (res == NULL)
	{
		printf("Error\n");
		return (0);
	}

	if (index == 0)
		return (head);

	while (head)
	{
		if (n == index)
		{
			res->n = head->n;
			res->next = head;
		}

		head = head->next;
		n++;
	}
	if (res == NULL)
		return (NULL);
	return (res);
}
