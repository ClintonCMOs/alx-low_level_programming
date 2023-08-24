#include "main.h"
/**
 * reverse_array - Reverses the contents of an array
 * @a: an array of integers
 * @n: number of elements to swap
 *
 * Return: Reverse array
 */
void reverse_array(int *a, int n)
{
	int i;
	int j;

	for (i = 0; i < n / 2; i++)
	{
		j = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = j;
	}
}
