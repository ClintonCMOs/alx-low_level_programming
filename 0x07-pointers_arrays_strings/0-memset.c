#include "main.h"
/**
 * _memset - A function that fills memory with a constant byte
 * @s: array to set
 * @b: value to set it as
 * @n: the number of times
 * Return: char value of s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
