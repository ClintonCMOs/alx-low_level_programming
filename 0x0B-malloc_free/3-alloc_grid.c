#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - A pointer to a created matrix (2 by 2 array)
 * @width: Width of 2 by 2 dimensional array
 * @height: Height of 2 by 2 dimensional array
 * Return: NULL If width <=0, height<=0, or alloc_grid fails
 *         otherwise: A pointer to the 2D array
 */
int **alloc_grid(int width, int height)
{
	int i, j;
	int **DD = malloc(sizeof(int *) * height);

	if (width <= 0 || height <= 0)
		return (NULL);
	if (DD == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		DD[i] = malloc(sizeof(int *) * width);
		if (DD[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(DD[j]);
			}
			free(DD);
		}
	}
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			DD[i][j] = 0;
	return (DD);
}
