#include "main.h"
#include <stdio.h>
/**
 * print_triangle - prints triangle
 * @size: integer size of the triangle
 *
 * Return: Triangle
 */
void print_triangle(int size)
{
	int a;
	int b;
	int c;

	if (size <= 0)
	{
		putchar('\n');
	}
	else
	{
		for (a = 1; a <= size; a++)
		{
			for (b = size - a; b > 0; b--)
			{
				putchar(' ');
			}
			for (c = 0; c < a; c++)
			{
				putchar('#');
			}
			putchar('\n');
		}
	}
}
