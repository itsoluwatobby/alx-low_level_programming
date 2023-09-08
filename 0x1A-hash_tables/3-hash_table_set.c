#include "hash_tables.h"

/**
 * hash_table_set - a function that adds an element to the hash table.
 * @ht: hash table
 * @key: hash key
 * @value: hash value
 *
 * Return: 1 onsuccess, 0 on error
*/

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	char *val;
	hash_node_t *new_node;
	unsigned int index, i = 0;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	val = strdup(value);
	if (val == NULL)
		return (0);

	/* check for key duplicate */
	index = key_index((const unsigned char *)key, ht->size);
	for (i = index; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = val;
			return (1);
		}
	}

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(val);
		return (0);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->value = val;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
