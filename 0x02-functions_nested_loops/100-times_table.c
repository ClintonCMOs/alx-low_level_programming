#include "main.h"
#include <stdio.h>
/**
 * print_times_table - print multiplication table
 * @n: number to be treated
 *
 * Return: matrix
 */
void print_times_table(int n)
{
	int t, u, v;

	if (n >= 0 && n <= 14)
	{
		for (t = 0; t <= n; t++)
		{
			for (u = 0; u <= n; u++)
			{
				v = t * u;
				if (v > 99)
				{
					_putchar(',');
					_putchar(32);
					_putchar((v / 100) + '0');
					_putchar(((v / 10) % 10) + '0');
					_putchar((v % 10) + '0');
				}
				else if (v > 9)
				{
					_putchar(',');
					_putchar(32);
					_putchar(32);
					_putchar(((v / 10) % 10) + '0');
					_putchar((v % 10) + '0');
				}
				else
				{
					if (u != 0)
					{
						_putchar(',');
						_putchar(32);
						_putchar(32);
						_putchar(32);
					}
					_putchar(v + '0');
				}
			}
		_putchar('\n');
		}
	}
}
