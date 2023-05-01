#include "lists.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * print_listint_safe - function that prints a listint_t linked list.
 * @head: first node of listint_t
 * Return: number of nodes
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t node_len = 0;
	void *ptr;

	if (head == NULL)
		exit(98);

	while (head)
	{
		ptr = head;
		printf("[%p] %d\n", ptr, head->n);
		head = head->next;
		node_len++;
	}
	return (node_len);
}
