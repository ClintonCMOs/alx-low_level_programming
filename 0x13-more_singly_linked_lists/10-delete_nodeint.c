#include "lists.h"
/**
  *delete_nodeint_at_index - Deletes a node at a given position
  *@head: A pointer to a pointer to the head node.
  @index: Index of the node to be deleted
  *Return: 1 if success -1 if fail
  */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temporary_ptr, *current = *head;
	unsigned int node_index;

	node_index = 0;
	if (current == NULL)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		free(current);
		return (1);
	}
	while (node_index < (index - 1))
	{
		if (current->next == NULL)
			return (-1);
		current = current->next;
		node_index++;
	}
	temporary_ptr = current->next;
	current->next = temporary_ptr->next;
	free(temporary_ptr);
	return (1);
}
