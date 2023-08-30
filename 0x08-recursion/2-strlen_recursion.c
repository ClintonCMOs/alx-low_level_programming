#include "main.h"
/**
 * _strlen_recursion - String length
 * @s: string to find length
 */
int _strlen_recursion(char *s)
{
	if (*s)
	{
		return (1 + _strlen_recursion(s + 1));
	}
	return (0);
}
