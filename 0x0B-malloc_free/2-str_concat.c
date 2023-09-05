#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * str_concat - Concatenates two strings
 * @s1: String one
 * @s2: string 2
 * Return: if memory allocation fails s1 or s2 null return NULL, else
 * return pointer
 */
char *str_concat(char *s1, char *s2)
{
	int i, len1, len2;
	char *joined;

	len1 = 0;
	len2 = 0;
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (i = 0; s1[i] != '\0'; i++)
	{
		len1++;
	}
	for (i = 0; s2[i] != '\0'; i++)
	{
		len2++;
	}
	joined = malloc(sizeof(char) * (len1 + len2 + 1));
	if (joined == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
	{
		joined[i] = s1[i];
	}
	for (i = 0; i < len2; i++)
	{
		joined[i + len1] = s2[i];
	}
	joined[i + len1] = '\0';
	return (joined);
}


