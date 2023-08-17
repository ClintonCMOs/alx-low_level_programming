#include <stdio.h>
/**
 * main - A program that finds and prints the largest
 * prime factor of a given number
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	unsigned int a = 2;
	unsigned long b = 612852475143;

	while (a != b)
	{
		if (b % a == 0)
		{
			b = b / a;
		}
		else
		{
			a++;
		}
	}
	printf("%lu\n", b);
	return (0);
}
