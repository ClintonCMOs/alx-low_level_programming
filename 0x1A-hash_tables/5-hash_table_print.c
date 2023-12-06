#include "hash_tables.h"
/**
 * hash_table_print - function that displays the hash table
 * @ht: the harshtable to be displayed
 * Return: nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int w; /*index*/
	hash_node_t *node;
	int hasprinted = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (w = 0; w < ht->size; w++)
	{
		node = ht->array[w];
		while (node != NULL)
		{
			if (hasprinted == 1)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			hasprinted = 1;
			node = node->next;
		}
	}
	printf("}\n");
}
