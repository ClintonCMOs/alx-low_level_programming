#include "main.h"
#include <stdio.h>
/**
 * more_numbers - number 0 to 14
 *
 * Return: numbers 0 to 14 10 times
 */
void more_numbers(void)
{
	int a;
	int b;

	for (a = 0; a <= 9; a++)
	{
		for (b = 0; b < 15 ; b++)
		{
			if (b >= 10)
			putchar(b / 10 + '0');
			putchar(b % 10 + '0');
		}
		putchar('\n');
	}
}


