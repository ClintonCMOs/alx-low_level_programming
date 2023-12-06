#include "hash_tables.h"
/**
 * hash_table_delete - deletes the hash table
 * @ht: the hash table
 * Return: nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int w;
	hash_node_t *node;
	hash_node_t *tempo;

	if (ht == NULL)
		return;

	for (w = 0; w < ht->size; w++)
	{
		node = ht->array[w];
		while (node != NULL)
		{
			tempo = node;
			node = node->next;
			free(tempo->key);
			free(tempo->value);
			free(tempo);
		}
		ht->array[w] = NULL;
	}
	free(ht->array);
	free(ht);
}
