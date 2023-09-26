#include "lists.h"
/**
 * add_nodeint_end - adds another node at the end of a listint_t list
 * @head: pointer to a pointer to the head of the list
 * @n: integer value to be stored in the another node
 * Return:  the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *added_node;
	listint_t *temporary_ptr;

	added_node = malloc(sizeof(listint_t));
	if (added_node == NULL)
		return (NULL);
	added_node->n = n;
	added_node->next = NULL;
	if (*head == NULL)
	{
		*head = added_node;
		return (added_node);
	}
	else
	{
		temporary_ptr = *head;
		while (temporary_ptr->next != NULL)
		{
			temporary_ptr = temporary_ptr->next;
		}
		temporary_ptr->next = added_node;

		return (added_node);
	}
}
