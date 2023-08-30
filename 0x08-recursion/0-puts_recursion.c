#include "main.h"
/**
 * _puts_recursion - A function that prints a string
 * @s: String to recurse through
 *
 * Return: A string
 */
void _puts_recursion(char *s)
{
	if (*s)
	{
		_putchar(*s);
		_puts_recursion(++s);
	}
	else
		_putchar('\n');
}
