#include "main.h"
#include "2-strlen.c"
/**
 * puts_half - Function prints half of a string
 * @str: string to be split into half and printed
 * Return: half of a string
 */
void puts_half(char *str)
{
	int a;
	int b;
	int len;

	len = _strlen(str);
	if ((len % 2) == 0)
	{
		b = len / 2;
	}
	else
	{
		b = (len + 1) / 2;
	}
	for (a = b; a < len; a++)
	{
		_putchar(str[a]);
	}
	_putchar('\n');
}
