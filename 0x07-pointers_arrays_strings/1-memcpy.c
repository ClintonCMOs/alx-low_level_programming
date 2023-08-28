#include "main.h"
/**
 * _memcpy - copies memory area
 * @dest: destination to copy to
 * @src: source to copy from
 * @n: n amount of times
 * Return: return the string value
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
