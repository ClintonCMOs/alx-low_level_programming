#include "function_pointers.h"
/**
 * int_index - Search using a comparison function
 * @array: The array of integers to search in
 * @size: The number of arrays in an element
 * @cmp: A pointer to the comparison function;
 * Return: index of first element, if no match (-1), if size <=0 (-1)
 */
int int_index(int *array, int size, int(*cmp)(int))
{
	int i;

	if (array == NULL || cmp || NULL || size <= 0)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}
	return (-1);
}
