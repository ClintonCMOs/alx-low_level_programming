#include "main.h"
#include "2-strlen.c"
/**
 * print_rev - Prints a string in reverse
 * @s: string to print
 * Return: string s
 */
void print_rev(char *s)
{
	int a;

	for (a = _strlen(s) - 1; a >= 0; a--)
	{
		_putchar(*(s + a));
	}
	_putchar('\n');
}
