#include "main.h"
/**
 * print_alphabet - entry
 * prints lowercase
 * Return: nothing
 */
void print_alphabet(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		_putchar(letter);
	}
	_putchar('\n');
}
