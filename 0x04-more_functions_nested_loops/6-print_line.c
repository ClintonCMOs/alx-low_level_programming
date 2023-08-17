#include "main.h"
#include <stdio.h>
/**
 * print_line - straight line in the terminal
 * @n: Number of time character _ is printed
 * Return: Line
 */
void print_line(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		putchar('_');
	}
	putchar('\n');
}
