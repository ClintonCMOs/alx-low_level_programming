#include "main.h"
#include <stdlib.h>
/**
 * create_array - creates an array of characters
 * @size: Array size to create
 * @c: Character to initialize array with
 * Return: NULL if size =0 or memory allocation fails. Or pointer
 */
char *create_array(unsigned int size, char c)
{
	char *array = malloc(sizeof(char) * size);
	unsigned int i;

	if (size == 0)
	{
		return (NULL);
	}
	if (array == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		array[i] = c;
	}
	return (array);
}
