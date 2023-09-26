#include "lists.h"
/**
  *sum_listint - Returns the sum of all data (n) in listint_t list.
  *
  *@head: A pointer to the head of the listint_t list.
  *
  *Return: Sum of all data (n) else 0 if empty.
  *
  */
int sum_listint(listint_t *head)
{
	int a;

	a = 0;
	while (head)
	{
		a += head->n;
		head = head->next;
	}
	return (a);
}
