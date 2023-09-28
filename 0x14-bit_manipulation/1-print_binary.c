#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	int shift;

	if (n == 0)
	{
		putchar('0');
		return;
	}
	for (shift = sizeof(unsigned long int) * 8 - 1; shift >= 0; shift--)
	{
		if (n & (1UL << shift))
			putchar('1');
		else
			putchar('0');
	}
}
