#include "lists.h"
/**
 * get_dnodeint_at_index - returns the nth node of a dlinkedlist
 * @head: pointer the headnode
 * @index: position of the node to be returned
 * Return: the nth node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *present = head;
	unsigned int counter = 0;

	while (present != NULL)
	{
		if (counter == index)
			return (present);

		present = present->next;
		counter++;
	}
	return (NULL); /*NODE does not exist at the specific pos*/
}
