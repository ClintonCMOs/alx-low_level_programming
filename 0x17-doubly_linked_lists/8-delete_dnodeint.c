#include "lists.h"
/**
 * delete_dnodeint_at_index - deletes the node at index of a linked list
 * @head: double pointer to the headnode
 * @index: position of the node to be deleted
 * Return: 1 if success , -1 if failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int w = 0; /*counter*/
	dlistint_t *present = *head;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(present);
		return (1);
	}
	while (present && w < index)
	{
		present = present->next;
		w++;
	}
	if (present == NULL) /*index not there*/
		return (-1);
	present->prev->next = present->next;
	if (present->next != NULL)
		present->next->prev = present->prev;
	free(present);

	return (1);
}
