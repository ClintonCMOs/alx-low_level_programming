#include "main.h"
#include "2-strlen.c"
/**
 * rev_string - A function that reverses a string
 * @s: string to be reversed
 * Return: String reverse
 */
void rev_string(char *s)
{
	int a;
	char b;

	for (a = 0; a < _strlen(s) / 2; a++)
	{
		b = s[a];
		s[a] = s[_strlen(s) - a - 1];
		s[_strlen(s) - a - 1] = b;
	}
}
