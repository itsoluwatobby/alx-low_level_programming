#include "lists.h"

/**
 * find_listint_loop - function that finds the loop in a linked list.
 * @head: list of listint_t
 * Return: 1 on success, else 0
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (head == NULL || head->next == NULL)
		return (NULL);

	slow = head->next;
	fast = head->next->next;

	while (fast)
	{
		if (slow == fast)
		{
			slow = head;

			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}

			return (slow);
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	return (NULL);
}
