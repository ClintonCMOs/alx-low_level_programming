#include "main.h"
#include <stdio.h>
/**
 * _puts - Prints a strings followed by a new line
 * @str: string to print
 * Return: String
 */
void _puts(char *str)
{
	int a;

	for (a = 0; *(str + a) != '\0'; a++)
	{
		_putchar(*(str + a));
	}
	_putchar('\n');
}
