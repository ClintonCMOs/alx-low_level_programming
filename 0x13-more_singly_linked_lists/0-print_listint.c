#include "lists.h"
/**
 * print_listint - A function that prints all elements
 * @h: Pointer to the head of the list
 * Return: The number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t node_index;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		node_index++;
		h = h->next;
	}
	return (node_index);
}

