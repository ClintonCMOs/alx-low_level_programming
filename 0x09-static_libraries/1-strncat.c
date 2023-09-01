#include "main.h"
#include <string.h>
/**
 * _strncat - Concatenate two strings
 * @dest: destination of concatenation
 * @src: source of concatenation
 * @n: use at most n bytes from src
 *
 * Return: char value
 */
char *_strncat(char *dest, char *src, int n)
{
	int b;
	int a = strlen(dest);

	for (b = 0; b < n && src[b] != '\0'; b++)
	{
		dest[a + b] = src[b];
	}
	dest[a + b] = '\0';
	return (dest);
}
