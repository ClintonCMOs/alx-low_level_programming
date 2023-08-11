#include <stdio.h>
/**
 * main - A program that prints alphabet in lowercase and uppercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter = 'a';
	int count = 0;

	while (letter <= 'z' && count < 3)
	{
		putchar(letter);
		letter++;
		count++;
	}

	letter = 'A';
	count = 0;

	while (letter <= 'Z' && count < 3)
	{
		putchar(letter);
		letter++;
		count++;
	}
	putchar('\n');
	return (0);
}

