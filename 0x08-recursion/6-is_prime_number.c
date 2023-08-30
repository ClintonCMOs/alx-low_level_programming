#include "main.h"
/**
 * prime_helper - does it for me
 * @i: helper int
 * @n: integer I'm testing
 * Return: value
 */
int prime_helper(int i, int n)
{
	if (n % i == 0 && n != i)
		return (0);
	if (n % i != 0 && i < n)
		return (prime_helper(i + 1, n));
	return (1);
}
/**
 * is_prime_number - A function testing if n is prime or not
 * @n: integer to compare
 * Return: boolean
 */
int is_prime_number(int n)
{
	int i = 2;

	if (n < 2)
		return (0);
	return (prime_helper(i, n));
}
