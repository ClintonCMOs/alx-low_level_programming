#include "main.h"
#include <stdlib.h>

/**
 * _realloc - A function that reallocates a memory block using malloc and free
 * @ptr: pointer to previously allocated memory block
 * @old_size: Size of the allocated space for ptr.
 * @new_size: size of the new memory block
 *
 * Return: Null if new_size == 0
 *         Ptr if new_size equals old_size
 *         Pointer to newly allocated memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int a;
	unsigned int range;
	char *new_ptr;

	if (ptr == NULL)
	{
		p = malloc(new_size);
		return (p);
	}

	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	else if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (p == NULL)
		return (NULL);

	range = new_size;
	if (new_size > old_size)
		range = old_size;

	new_ptr = ptr;
	for (a = 0; a < range; a++)
		p[a] = new_ptr[a];

	free(ptr);

	return (p);
}
