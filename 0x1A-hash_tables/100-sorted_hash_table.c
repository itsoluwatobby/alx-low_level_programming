#include "hash_tables.h"

/**
 * shash_table_create - function that creates a sorted hash table.
 * @size: size of the new sorted hash table.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new sorted hash table.
*/

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int index;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (index = 0; index < size; index++)
		ht->array[index] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - function that adds an element to a sorted hash table.
 * @ht: pointer to the sorted hash table.
 * @key: key to add - cannot be an empty string.
 * @value: value associated with key.
 *
 * Return: 0 onerror, 1 onsuccess.
*/

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *temp;
	char *val;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	val = strdup(value);
	if (val == NULL)
		return (0);

	temp = ht->shead;
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = val;
			return (1);
		}
		temp = temp->snext;
	}
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
	{
		free(val);
		return (0);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(val);
		free(new_node);
		return (0);
	}
	helper_func_to_set(ht, new_node, temp, key, val);

	return (1);
}

/**
 * helper_func_to_set - continuation of shash_table_set function
 * @ht: A pointer to the sorted hash table.
 * @new_node: new shash node
 * @temp: temporary shash node storage
 * @key: The key to add - cannot be an empty string.
 * @val: duplicated value
 *
 * Return: 1 onsuccess, else 0
*/

int helper_func_to_set(shash_table_t *ht, shash_node_t *new_node,
		shash_node_t *temp, const char *key, char *val)
{
	unsigned long int index;

	index = key_index((const unsigned char *)key, ht->size);

	new_node->value = val;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	if (ht->shead == NULL)
	{
		new_node->sprev = NULL;
		new_node->snext = NULL;
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		temp = ht->shead;
		while (temp->snext != NULL && strcmp(temp->snext->key, key) < 0)
			temp = temp->snext;
		new_node->sprev = temp;
		new_node->snext = temp->snext;
		if (temp->snext == NULL)
			ht->stail = new_node;
		else
			temp->snext->sprev = new_node;
		temp->snext = new_node;
	}
	return (1);
}

/**
 * shash_table_get - function retrieve the value associated with
 *                   a key in a sorted hash table.
 * @ht: pointer to the sorted hash table.
 * @key: key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
*/

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

	if (node == NULL)
		return (NULL);
	return (node->value);
}

/**
 * shash_table_print - function that prints a sorted hash table in order.
 * @ht: pointer to the sorted hash table.
*/

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}
