#include "main.h"
#include <stdlib.h>
/**
 * string_nconcat - Concatenates the strings s1 and s2
 * @s1: String 1
 * @s2: String 2
 * @n: Number of bytes concatenated
 * Return: Pointer to concatenated string or NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concatenated;
	unsigned int a, len1, len2;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	len1 = 0;
	len2 = 0;
	while (s1[len1] != '\0')
	{
		len1++;
	}
	while (s2[len2] != '\0')
	{
		len2++;
	}
	if (n >= len2)
	{
		n = len2;
	}
	concatenated = malloc(sizeof(char) * n + len1 + 1);
	if (concatenated == NULL)
		return (NULL);
	for (a = 0; a < len1; a++)
	{
		concatenated[a] = s1[a];
	}
	for (a = 0; a < n; a++)
	{
		concatenated[a + len1] = s2[a];
	}
	concatenated[a + len1] = '\0';
	return (concatenated);
}
