#include "main.h"
/**
 * times_table - print 9 times table
 *
 * Return: Empty
 */
void times_table(void)
{
	int d, e;

	for (d = 0; d < 10; d++)
	{
		for (e = 0; e < 10; e++)
		{
			if (d == 0)
				_putchar(' ');
				_putchar(d + '0');
			else if ((d * e) < 10)
			{
				_putchar(' ');
				_putchar(' ');
				_putchar((d * e) % 10 + '0');
			}
			else
			{
				_putchar(' ');
				_putchar((d * e) / 10 + '0');
				_putchar((d * e) % 10 + '0');

			}
			if (d != 9)
				_putchar(',');
		}
		_putchar('\n');
	}
}
