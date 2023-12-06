#include "hash_tables.h"
#include <string.h>
/**
 * hash_table_get - function that retrieves a value from the hash table
 * @ht: the hash table
 * @key: key associated with the value
 * Return: key if found, NULLL if not
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int w; /*index*/

	if (ht == NULL || key == NULL)
		return (NULL);
	w = key_index((const unsigned char *)key, ht->size);
	node = ht->array[w];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next; /*tranverse to the next node as it checks*/
	}
	return (NULL);
}
