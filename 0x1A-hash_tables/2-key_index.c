#include "hash_tables.h"

/**
 * key_index - funtcion that returns the index of a key
 * @key: given key
 * @size: size of hash table
 *
 * Return: index of the key
*/

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}

/**
 * shash_table_print_rev - function that prints a sorted
 *                              hash table in reverse order.
 * @ht: pointer to the sorted hash table to print.
*/

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->stail;

	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - function to delete a sorted hash table.
 * @ht: pointer to the sorted hash table to delete.
*/

void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *temp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node)
	{
		temp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = temp;
	}

	free(head->array);
	free(head);
}
