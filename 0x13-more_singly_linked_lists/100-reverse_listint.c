#include "lists.h"
/**
  *reverse_listint - Reverses a listint_t linked list.
  *
  *@head: A pointer to a pointer to the head node.
  *
  *Return: A pointer to the first node of the reversed list.
  */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev;
	listint_t *next;

	if (head == NULL || *head == NULL)
		return (NULL);
	next = NULL;
	while ((*head)->next != NULL)
	{
		prev = (*head)->next;
		(*head)->next = next;
		next = *head;
		*head = prev;
	}
	(*head)->next = next;
	return (*head);
}
