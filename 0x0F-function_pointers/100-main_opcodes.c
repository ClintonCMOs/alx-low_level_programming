#include <stdio.h>
#include <stdlib.h>
/**
 * main - Prints the opcodes of its own main function
 * @argc: number of arguments supplied .
 * @argv: array of ptrs to the arguments.
 * Return: Success
 */
int main(int argc, char *argv[])
{
	int b;
	int i;
	int (*address)(int, char **) = main;
	unsigned char opcode;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	b = atoi(argv[1]);

	if (b < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < b; i++)
	{
		opcode = *(unsigned char *)address;
		printf("%.2x", opcode);

		if (i == b - 1)
			continue;
		printf(" ");

		address++;
	}

	printf("\n");

	return (0);
}
