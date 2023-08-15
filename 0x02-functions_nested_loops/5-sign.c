#include "main.h"
/**
 * print_sign - print sign of a number
 * @n: number to be checked
 *
 * Return: 1, -1, or 0
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}
