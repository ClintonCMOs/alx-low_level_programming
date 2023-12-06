#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - function that adds an element to the harsh table
 * @ht: the hashtable
 * @key: key/ item to be placed in the hash tablle
 * @value: value associated with the key
 * Return: 1 if success , 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int w = 0; /*index*/
	hash_node_t *newnode = NULL;
	hash_node_t *temp = NULL; /*tranverses the linked List*/

	if (ht == NULL || key == NULL || (strcmp(key, "") == 0))
	{
		return (0); /* input that is invalid*/
	}

	w = key_index((unsigned char *)key, ht->size);
	temp = ht->array[w];

	if (temp && strcmp(key, temp->key) == 0)
	{
		free(temp->value);
		temp->value = strdup(value);
		return (1);
	}

	newnode = malloc(sizeof(hash_node_t));

	if (newnode == NULL)
		return (0);

	newnode->key = strdup(key);
	newnode->value = strdup(value);

	newnode->next = ht->array[w]; /**
				       *set the next ptr of newnode to point to the
				       *current head of the linked list at the calcluated in
				       */
	ht->array[w] = newnode;/**
				*we update the array at the calcluated index to point to
				*the newnode, by doing this we make the newnode the new
				*head of the linked list at the index
				*/

	return (1);
}
