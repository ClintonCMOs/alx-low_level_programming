#include <stdio.h>
#include "lists.h"

/**
 * print_list - Prints all the elements of the list "list_t"
 * @h: The list "list_t"
 *
 * Return: The number of nodes in h.
 */

size_t print_list(const list_t *h)
{
	size_t node_count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");

		else
			printf("[%d] %s\n", h->len, h->str);

		node_count++;
		h = h->next;
	}

	return (node_count);
}
