#include "main.h"
/**
 * int_islower - entry point
 *
 * Return: 1 if lowercase and 0 otherwise
 */
void int_islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
