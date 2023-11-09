#include "lists.h"
/**
 * free_dlistint - frees a dlinked list
 * @head: pointer to the headnode
 * Return: nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp_holder;

	while (head)
	{
		tmp_holder = head->next;
		free(head);
		head = tmp_holder;
	}
}
