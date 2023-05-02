#include "lists.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int has_loops(listint_t *head);

/**
 * has_loops - function that checks if a list has a loop
 * @head: list of listint_t
 * Return: 1 on success, else 0
 */

int has_loops(listint_t *head)
{
	listint_t *slow = head->next, *fast = head->next->next;
	size_t node_len = 1;

	if (head == NULL || head->next == NULL)
		return (0);


	while (fast)
	{
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				node_len++;
				slow = slow->next;
				fast = fast->next;
			}
			slow = slow->next;
			while (slow != fast)
			{
				node_len++;
				slow = slow->next;
			}
			return (node_len);
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	return (0);
}

/**
 * free_listint_safe - function that frees a listint_t list.
 * @h: first node of listint_t
 * Return: number of nodes
 */

size_t free_listint_safe(listint_t **h)
{
	size_t node_len = 0, index = 0;
	listint_t *temp;

	if (*h == NULL)
		return (0);

	node_len = has_loops(*h);

	if (node_len == 0)
	{
		for (; *h != NULL; node_len++)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
		}
	}
	else
	{
		for (index = 0; index < node_len; index++)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
		}
		*h = NULL;
	}

	h = NULL;
	return (node_len);
}
