#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * add_node_end - function that adds a new node at the end
 *		of a list_t list.
 * @head: pointer to a given node
 * @str: given string
 * Return: new node
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *tail;
	unsigned int len = 0;
	char *copy;

	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		printf("Error\n");
		return (NULL);
	}

	copy = strdup(str);
	if (copy == NULL)
	{
		free(new);
		return (NULL);
	}

	while (str[len] != '\0')
		len++;

	new->str = copy;
	new->len = len;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		tail = *head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = new;
	}

	return (*head);
}
