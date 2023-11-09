#include "lists.h"
/**
 * add_dnodeint_end - adds a new node at the end of dlinked list
 * @head: double pointer to the head node
 * @n: data of the node
 * Return: address of the new element
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node = NULL;
	dlistint_t *presentnode = NULL;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	if (*head)
	{
		presentnode = *head;
		while (presentnode->next != NULL)
			presentnode = presentnode->next;
		new_node->next = NULL;
		new_node->prev = presentnode;
		presentnode->next = new_node;
		return (new_node);
	}
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
	return (*head);
