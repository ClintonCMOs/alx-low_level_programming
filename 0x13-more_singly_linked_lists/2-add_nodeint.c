#include "lists.h"
/**
  *add_nodeint - Includes a new node at the beginning of listint_t.
  *
  *@head: pointer to a pointer to the head of the list
  *
  *@n: integer value to be stored in the new node
  *
  *Return: New element address or NULL if it fails
  */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *added_node;

	added_node = malloc(sizeof(listint_t));
	if (added_node == NULL)
		return (NULL);
	added_node->n = n;
	added_node->next = *head;
	*head = added_node;
	return (*head);
}
