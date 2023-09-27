#include "lists.h"
/**
 * loop_count - Counts the number of unique node_count
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: 0 (not looped),the number of unique node_count in the list
 */

size_t loop_count(listint_t *head)
{
	listint_t *start, *end;

	size_t node_count;

	node_count = 1;
	if (head == NULL || head->next == NULL)
		return (0);

	start = head->next;
	end = (head->next)->next;

	while (end)
	{
		if (start == end)
		{
			start = head;
			while (start != end)
			{
				node_count++;
				start = start->next;
				end = end->next;
			}

			start = start->next;
			while (start != end)
			{
				node_count++;
				start = start->next;
			}

			return (node_count);
		}

		start = start->next;
		end = (end->next)->next;
	}

	return (0);
}

/**
 * free_listint_safe - safely frees a list
 * @h: A pointer to a pointer to the head node.
 * Return: size of freed list
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *temp_ptr;

	size_t node_count, a;

	node_count = loop_count(*h);

	if (node_count == 0)
	{
		for (; h != NULL && *h != NULL; node_count++)
		{
			temp_ptr = (*h)->next;
			free(*h);
			*h = temp_ptr;
		}
	}

	else
	{
		for (a = 0; a < node_count; a++)
		{
			temp_ptr = (*h)->next;
			free(*h);
			*h = temp_ptr;
		}

		*h = NULL;
	}

	h = NULL;

	return (node_count);
}
