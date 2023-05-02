#include "lists.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * has_a_loop - function that checks if a list has a loop
 * @head: list of listint_t
 * Return: 1 on success, else 0
 */

int has_a_loop(const listint_t *head)
{
	const listint_t *slow, *fast;
	size_t node_len = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	slow = head->next;
	fast = head->next->next;

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
 * print_listint_safe - function that prints a listint_t linked list.
 * @head: first node of listint_t
 * Return: number of nodes
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t node_len = 0, idx = 0;

	node_len = has_a_loop(head);

	if (node_len == 0)
	{
		for (; head != NULL; node_len++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (idx = 0; idx < node_len; idx++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (node_len);
}
