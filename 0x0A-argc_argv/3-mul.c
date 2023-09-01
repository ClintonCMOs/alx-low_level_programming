#include <stdio.h>
#include <stdlib.h>
/**
 * main - A program that prints 2 numbers
 * @argc: counts the arguments passed
 * @argv: argument vector
 * Return: 0 if success and 1 if error
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
		return (0);
	}
}
