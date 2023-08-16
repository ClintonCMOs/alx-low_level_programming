#include "main.h"
/**
 * print_last_digit - printing last digit
 * @v: number to be treated
 *
 * Return: value of number
 */
int print_last_digit(int v)
{
	int l;

	l = v % 10;
	if (l < 0)
	{
		l = l * -1;
	}
	_putchar(l + '0');
	return (l);
}
