#include "main.h"
#include "2-strlen.c"

/**
 * _strcpy - copies string pointed
 * @dest: destination to copy strings
 * @src: src
 *
 * Return: A character
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; a <= _strlen(src); a++)
	{
		dest[a] = src[a];
	}
	return (dest);
}
