#include "main.h"
#include <stdio.h>
/**
 * print_numbers - print numbers 0 to 9
 * @i: integer 0 to 9
 * Return: Numbers from 0 to 9
 */
void print_numbers(void)
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		putchar(i + '0');
	}
	putchar('\n');
}
