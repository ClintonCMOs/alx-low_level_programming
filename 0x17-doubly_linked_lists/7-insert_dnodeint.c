#include "lists.h"
/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: Double pointer to the head node
 * @idx: index of the list where the new node shld be added, idx = 0
 * @n: data to put in the new node
 * Return: The address of the new node at index idx, NULLif failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *temp_holder = *h;
	unsigned int v = 0; /*counter*/

	if (idx == 0)
		return (add_dnodeint(h, n));
	while (temp_holder && v < idx - 1)
	{
		temp_holder = temp_holder->next;
		v++;
	}
	if (!temp_holder)
		return (NULL);
	if (!temp_holder->next) /*insert node at the end of the list*/
		return (add_dnodeint_end(h, n));
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = temp_holder->next;
	new_node->prev = temp_holder;
	temp_holder->next->prev = new_node;
	temp_holder->next = new_node;

	return (new_node);
}
