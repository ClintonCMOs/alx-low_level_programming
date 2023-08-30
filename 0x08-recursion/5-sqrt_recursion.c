#include "main.h"
/**
 * root_helper - helps decide if i am right
 * @a: integer to guess
 * @n: integer to find sqrt of
 * Return: Value of root
 */
int root_helper(int a, int n)
{
	int c;

	if (a * a != n)
	{
		if (a > n)
		{
			return (-1);
		}
		c = root_helper(a + 1, n);
		return (c + 1);
	}
	return (0);
}
/**
 * _sqrt_recursion - Function that returns the natural sqrt of number
 * @n: Number to get its sqrt
 *
 * Return: Sqrt or -1
 */
int _sqrt_recursion(int n)
{
	int a = 0;

	if (root_helper(a, n) == n && n != 1)
	{
		return (-1);
	}
	else
	{
		return (root_helper(a, n));
	}
}
