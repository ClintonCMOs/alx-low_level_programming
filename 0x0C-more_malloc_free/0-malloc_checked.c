#include "main.h"
#include <stdlib.h>
/**
 * malloc_checked - A function that allocates memory using malloc
 * @b: integer to check
 * Return: A pointer to allocated memory or terminate with 98
 */
void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
		exit(98);
	}
	return (ptr);
}
