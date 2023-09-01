#include <stdio.h>
/**
 * main - Prints number of arguments passed through
 * @argc: Argument count
 * @argv: argument vector that is pointer to the arguments
 *
 * Return: 0
 */
int main(int argc, char __attribute__((__unused__)) *argv[])
{
	printf("%d\n", argc - 1);
	return (0);
}
