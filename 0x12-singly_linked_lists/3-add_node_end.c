#include <stdio.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: A pointer to a pointer to the head of the list.
 * @str: The string to be duplicated and added to the new node.
 *
 * Return: The address of the new element, or NULL if it fails.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *current = *head;
	list_t *end_node = malloc(sizeof(list_t));

	if (str == NULL)
		return (NULL);

	if (end_node == NULL)
		return (NULL);
	end_node->str = strdup(str);

	if (end_node->str == NULL)
	{
		free(end_node);
		return (NULL);
	}
	end_node->len = strlen(str);
	end_node->next = NULL;

	if (*head == NULL)
	{
		*head = end_node;
		return (end_node);
	}

	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = end_node;
	return (end_node);
}
