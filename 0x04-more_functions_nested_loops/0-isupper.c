#include "main.h"
#include <stdio.h>

/**
 * _isupper - checks for uppercase characters
 *@c: character to check
 * Return: 1 when uppercase and 0 when lowercase.
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
