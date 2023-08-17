#include "main.h"
#include <stdio.h>
/**
 * print_diagonal - Prints diagonal line on the terminal
 * @n: number of times the character n should be printed
 * Return: \n when  n is 0 or less
 */
void print_diagonal(int n)
{
	int a;
	int b;

	if (n <= 0)
	{
		putchar('\n');
	}
	else
	{
		for (a = 0; a < n; a++)
		{
			for (b = 0; b < a; b++)
			{
				putchar(' ');
			}
			putchar('\\');
			putchar('\n');
		}
	}
}
