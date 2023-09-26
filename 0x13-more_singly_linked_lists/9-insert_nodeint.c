#include "lists.h"
/**
  *insert_nodeint_at_index - Inserts a new node at a given position
  *@head: A pointer to a pointer to the head node.
  *@idx: The index at which the new node should be inserted.
  *@n: The data for the new node.
  *Return: Adress of new node or NULL if it fails
  */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current = *head;
	unsigned int node;

	node = 0;
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	if (idx == 0)
	{
		new_node->next = current;
		*head = new_node;
		return (new_node);
	}
	while (node < (idx - 1))
	{
		if (current == NULL || current->next == NULL)
			return (NULL);
		current = current->next;
		node++;
	}
	new_node->next = current->next;
	current->next = new_node;
	return (new_node);
}
