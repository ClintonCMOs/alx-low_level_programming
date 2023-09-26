#include "lists.h"
/**
 * listint_len - A function that returns no of elements
 * @h: Pointer to the head of the list
 * Return: The number of elements in the list
 */
size_t listint_len(const listint_t *h)
{
	size_t node_index = 0;

	while (h != NULL)
	{
		node_index++;
		h = h->next;
	}
	return (node_index);
}
