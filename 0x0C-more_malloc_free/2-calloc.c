#include "main.h"
#include <stdlib.h>
/**
 * _calloc - A function that allocates memory of array using malloc
 * @nmemb: number of elements in the array
 * @size: size of each element
 * Return: NULL or pointer
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int a;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	a = 0;
	while (a < nmemb * size)
	{
		ptr[a] = 0;
		a++;
	}
	return (ptr);
}
