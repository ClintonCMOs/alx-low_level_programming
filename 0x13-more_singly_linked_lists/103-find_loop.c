#include "lists.h"
/**
  *find_listint_loop - finds a loop in a linked list
  *@head: A pointer to a pointer to the head node.
  *
  *Return: address of start node or NULL if no loop
  *
  */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *pointer, *loop_tail;

	if (head == NULL)
		return (NULL);
	for (loop_tail = head->next; loop_tail != NULL; loop_tail = loop_tail->next)
	{
		if (loop_tail == loop_tail->next)
			return (loop_tail);
		for (pointer = head; pointer != loop_tail; pointer = pointer->next)
			if (pointer == loop_tail->next)
				return (loop_tail->next);
	}
	return (NULL);
}
