#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * _strdup - Returns a pointer to newly malloc with string copy
 * @str: String to duplicate
 * Return: NULL if malloc fails or str is null, otherwise return pointer
 */
char *_strdup(char *str)
{
	char *duplicate;

	duplicate = malloc(strlen(str) + 1);
	if (duplicate == NULL)
	{
		return (NULL);
	}
	if (str == NULL)
	{
		return (NULL);
	}
	strcpy(duplicate, str);
	return (duplicate);
}
