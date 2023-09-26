#include "lists.h"
/**
 * free_listint2 - frees a listint_t list and sets the head to NULL
 * @head: pointer to a pointer to the head of the list
 */
void free_listint2(listint_t **head)
{
	listint_t *temporary_ptr;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		temporary_ptr = *head;
		free(*head);
		*head = temporary_ptr->next;
	}
	*head = NULL;
}
