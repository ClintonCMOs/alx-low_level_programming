#include "main.h"
/**
 * print_binary - print binary
 * @n: integer to print
 */
void print_binary(unsigned long int n)
{
	unsigned long int a = 1;

	a <<= ((sizeof(a) * 8) - 1);
	if (n == 1)
	{
		_putchar('1');
		return;
	}
	if (n == 0)
	{
		_putchar('0');
		return;
		}
	while (a > 0)
	{
		if ((a & n) == 0)
			a = a >> 1;
		else
			break;
	}
	while (a > 0)
	{
		if ((a & n) == 0)
			_putchar('0');
		else
			_putchar('1');
		a = a >> 1;
	}

}
