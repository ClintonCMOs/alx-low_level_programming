#include "main.h"
/**
 * swap_int - Swap two integers
 * @a: first integer to be swapped
 * @b: second integer to be swapped
 *
 * Return: Always0
 */
void swap_int(int *a, int *b)
{
	int c = *a;
	int d = *b;
	*a = d;
	*b = c;
}
