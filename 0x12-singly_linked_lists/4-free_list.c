#include "lists.h"
#include <stdlib.h>

/**
 * free_list - function that frees a list_t list
 * @head: given node
 */

void free_list(list_t *head)
{
	list_t *buffer;


	while (head)
	{
		buffer = head->next;
		free(head);
		head = buffer;
	}
}
