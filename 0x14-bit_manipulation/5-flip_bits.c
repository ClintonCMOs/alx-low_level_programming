#include "main.h"
/**
 * flip_bits - Counts the number of bits needed to flip.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flip_result;
	unsigned int count = 0;

	flip_result = n ^ m;
	while (flip_result > 0)
	{
		count += flip_result & 1;
		flip_result >>= 1;
	}
	return (count);
}
