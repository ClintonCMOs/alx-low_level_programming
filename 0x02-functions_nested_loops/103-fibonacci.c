#include <stdio.h>
/**
 * main - sum
 *
 * Return:A lways 0
 */
int main(void)
{
	int t;
	unsigned long int u, v, next, sum;

	u = 1;
	v = 2;
	sum = 0;
	for (t = 1; t <= 33; t++)
	{
		if (u < 4000000 && (u % 2) == 0)
		{
			sum = sum + u;
		}
		next = u + v;
		u = v;
		v = next;
	}
	printf("%lu\n", sum);
	return (0);
}
