#include "main.h"
#include <stdlib.h>
/**
 * array_range - A function that creates an array of integers
 * @min: minimum value in the range
 * @max: maximum value in the range
 * Return: Pointer to the new array or NULL
 */
int *array_range(int min, int max)
{
	int *result;
	int a;

	if (min > max)
		return (NULL);
	result = (int *)malloc(sizeof(int) * (max - min + 1));
	if (result == NULL)
		return (NULL);
	for (a = 0; a <= max - min; a++)
	{
		result[a] = min + a;
	}
	return (result);
}
