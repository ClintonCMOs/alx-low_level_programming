#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - function that creates a hash table
 * @size: size of the array
 * Return: the newly created hast table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_htable;
	unsigned long int w; /*counter of the array*/

	new_htable = (hash_table_t *)malloc(sizeof(hash_table_t));
	if (new_htable == NULL)
		return (NULL);

	new_htable->array = (hash_node_t **)malloc(sizeof(hash_node_t *) * size);
	if (new_htable->array == NULL)
	{
		free(new_htable);
		return (NULL);
	}
	for (w = 0; w < size; w++)
	{
		new_htable->array[w] = NULL;
	}
	new_htable->size = size;
	return (new_htable);
}
