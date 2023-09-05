#include "main.h"
#include <stdlib.h>
/**
 * argstostr - concatenates all arguments of a program
 * @ac: NO of arguments
 * @av: array pointer to arguments
 * Return: NULL when error or ac||av =0
 */
char *argstostr(int ac, char **av)
{
	int a, b;
	int k = 0;
	int n = 0;
	char *str;

	if (ac <= 0 || av == NULL)
		return (NULL);

	for (a = 0; a < ac; a++)
	{
		for (b = 0; av[a][b]; b++)
			n++;
		n++;
	}

	n++;
	str = malloc(sizeof(char) * n);

	if (str == NULL)
		return (NULL);

	for (a = 0; a < ac; a++)
	{
		for (b = 0; av[a][b]; b++)
		{
			str[k] = av[a][b];
			k++;
		}
		str[k] = '\n';
		k++;
	}

	str[k] = '\0';
	return (str);
}
