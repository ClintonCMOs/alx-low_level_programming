#include "main.h"
#include <stdio.h>
/**
 * print_to_98 - all numbers from v to 98
 * @v: is the starting number
 *
 * Return: Always 0
 */
void print_to_98(int v)
{
	if (v <= 98)
	{
		for (; v <= 98; v++)
		{
			if (v == 98)
			{
				printf("%d", v);
				printf("\n");
				break;
			}
			else
			{
				printf("%d, ", v);
			}
		}
	}
	else
	{
		for (; v >= 98; v--)
		{
			if (v == 98)
			{
				printf("%d", v);
				printf("\n");
				break;
			}
			else
			{
				printf("%d, ", v);
			}
		}
	}
}
