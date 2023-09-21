#include "lists.h"

/**
 * list_len - a function that returns the number of
 *            elements in a linked list_t list
 * @h: The linked list "list_t"
 *
 * Return: No of elements in h.
 */
size_t list_len(const list_t *h)
{
	size_t element_count = 0;

	while (h)
	{
		element_count++;
		h = h->next;
	}

	return (element_count);
}
