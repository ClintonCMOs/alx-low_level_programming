#include "lists.h"
/**
* find_listint_loop_linked - finds a loop in a linked list
* @head: A pointer to a pointer to the head node.
* Return: address of node where loop begins else NULL
*/

listint_t *find_listint_loop_linked(listint_t *head)
{
	listint_t *pointer, *tail_end;

	if (head == NULL)
		return (NULL);

	for (tail_end = head->next; tail_end != NULL; tail_end = tail_end->next)
	{
		if (tail_end == tail_end->next)
			return (tail_end);
		for (pointer = head; pointer != tail_end; pointer = pointer->next)
			if (pointer == tail_end->next)
				return (tail_end->next);
	}
	return (NULL);
}

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: A pointer to the head node.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t length;
	int loops;
	listint_t *loopsnode;

	loopsnode = find_listint_loop_linked((listint_t *) head);

	for (length = 0, loops = 1; (head != loopsnode || loops) && head != NULL; length++)
	{
		printf("[%p] %d\n", (void *) head, head->n);
		if (head == loopsnode)
			loops = 0;
		head = head->next;
	}

	if (loopsnode != NULL)
		printf("-> [%p] %d\n", (void *) head, head->n);
	return (length);
}
