#include "main.h"
/**
 * factorial - Function that returns factorial of a number
 * @n: Number to get its factorial
 * Return: factorial or -1
 */
int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n > 0)
	{
		return (n * factorial(n - 1));
	}
	else
	{
	return (1);
	}
}
