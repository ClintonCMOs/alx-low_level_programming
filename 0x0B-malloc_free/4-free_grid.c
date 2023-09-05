#include "main.h"
#include <stdlib.h>
/**
 * free_grid - A function that Frees 2D grid by alloc_grid
 * @grid: grid to check
 * @height: grid height
 */
void free_grid(int **grid, int height)
{
	int i = 0;

	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	if (height <= 0)
		return;
	if (grid == NULL)
		return;
}
