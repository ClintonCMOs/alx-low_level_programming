#include "lists.h"
/**
 * sum_dlistint - returns the sum of all the data(n) of a dlinked list
 * @head: pointer to the head node
 * Return: sum of all the dats(n)
 */
int sum_dlistint(dlistint_t *head)
{
	int sum_data = 0;
	dlistint_t *present = head;

	while (present != NULL)
	{
		sum_data = sum_data + present->n;
		present = present->next;
	}
	return (sum_data);
