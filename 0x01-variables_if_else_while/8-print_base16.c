#include <stdio.h>
/**
 * main - Hexadecimal printer
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char hexa;

	for (hexa = '0'; hexa <= '9'; hexa++)
	{
		putchar(hexa);
	}
	for (hexa = 'a'; hexa <= 'f'; hexa++)
	{
		putchar(hexa);
	}
	putchar('\n');
	return (0);
}
