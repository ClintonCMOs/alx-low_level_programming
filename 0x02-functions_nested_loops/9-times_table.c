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
				putchar(d + '0');
			else if ((d * e) < 10)
			{
				putchar(' ');
				putchar(' ');
				putchar((d * e) % 10 + '0');
			}
			else
			{
				putchar(' ');
				putchar((d * e) / 10 + '0');
				putchar((d * e) % 10 + '0');

			}
			if (d != 9)
				putchar(',');
		}
		putchar('\n');
	}
}
