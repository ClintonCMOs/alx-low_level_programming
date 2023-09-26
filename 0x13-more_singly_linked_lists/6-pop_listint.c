#include "lists.h"
/**
 * pop_listint - Deletes the head node of a listint_t linked list
 * @head: A pointer to a pointer to the head node.
 * Return: The data (n) of the deleted head node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	int list_value = 0;
	listint_t *temporary_ptr;

	if (*head == NULL)
		return (0);
	temporary_ptr = *head;
	list_value = temporary_ptr->n;
	*head = temporary_ptr->next;
	free(temporary_ptr);
	return (list_value);
}
