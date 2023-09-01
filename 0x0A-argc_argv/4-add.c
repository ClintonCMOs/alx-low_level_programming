#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - A function that adds positive numbers
 *
 * @argc: Argument count
 * @argv: Argument vect
 *
 * Return: 0 if no number is passed, 1 and print Error if isnotdigit
 */

int main(int argc, char *argv[])
{
	int num1, num2, sum = 0;

	for (num1 = 1; num1 < argc; num1++)
	{
		for (num2 = 0; argv[num1][num2] != '\0'; num2++)
		{
			if (!isdigit(argv[num1][num2]))
			{
				printf("Error\n");
				return (1);
			}
		}
		sum += atoi(argv[num1]);
	}
	printf("%d\n", sum);
	return (0);
}
