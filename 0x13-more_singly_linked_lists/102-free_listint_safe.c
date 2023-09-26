#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: A pointer to a pointer to the head node.
 * Return: the size of the list freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tmp_ptr, *original;
	size_t a;
	int remain;

	original = *h;
	for (a = 0; original; a++)
	{
		remain = original - original->next;
		if (remain > 0)
		{
			tmp_ptr = original->next;
			free(original);
			original = tmp_ptr;
		}
		else
		{
			free(original);
			*h = NULL;
			break;
		}
	}
	*h = NULL;
	return (a);
}

