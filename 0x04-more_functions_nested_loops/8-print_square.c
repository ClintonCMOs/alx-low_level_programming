#include "main.h"
#include <stdio.h>
/**
 * print_square - Prints a square followed by a new line
 * @size: Size of the square
 *
 * Return: if equal to 0 or less print new line, # to print square
 */
void print_square(int size)
{
	int a;
	int b;

	a = 0;

	if (size <= 0)
	{
		putchar('\n');
	}
	while (a < size && size > 0)
	{
		b = 0;
		while (b < size && size > 0)
		{
			putchar('#');
			b++;
		}
		a++;
		putchar('\n');
	}
}
