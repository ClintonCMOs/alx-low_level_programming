#include "function_pointers.h"
#include <stdio.h>
/**
 * array_iterator - Applies a function to each element of integer array
 * @array: Integer array to iterate over
 * @size: The size of the array
 * @action: A pointer to function to apply to each element
 */
void array_iterator(int *array, size_t size, void(*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
