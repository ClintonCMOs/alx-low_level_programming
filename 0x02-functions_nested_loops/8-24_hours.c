#include "main.h"
/**
 * jack_bauer - print every minute
 * starting 00:00 to 23:59
 */
void jack_bauer(void)
{
	int u, v;

	u = 0;
	while (u < 24)
	{
		v = 0;
		while (v < 60)
		{
			_putchar((u / 10) + '0');
			_putchar((u % 10) + '0');
			_putchar(':');
			_putchar((v / 10) + '0');
			_putchar((v % 10) + '0');
			_putchar('\n');
			v++;
		}
		u++;
	}
}


