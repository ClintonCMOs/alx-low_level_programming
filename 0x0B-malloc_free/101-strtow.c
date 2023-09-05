#include "main.h"
#include <stdlib.h>

/**
 * wordcount - A function that counts no. of words in a string
 * @c: string to count
 *
 * Return: number of words in string
 */
int wordcount(char *c)
{
	int a;
	int b = 0;

	for (a = 0; c[a]; a++)
	{
		if (c[a] == ' ')
		{
			if (c[a + 1] != ' ' && c[a + 1] != '\0')
				b++;
		}
		else if (a == 0)
			b++;
	}
	b++;
	return (b);
}

/**
 * strtow - A function that splits a string into words
 * @str: string to split into two words
 *
 * Return: Null if(str=null ,str = "" or error) else return pointer to array
 */

char **strtow(char *str)
{
	int a, d, e, f, b = 0, wc = 0;
	char **w;

	if (str == NULL || *str == '\0')
		return (NULL);
	b = wordcount(str);
	if (b == 1)
		return (NULL);
	w = (char **)malloc(b * sizeof(char *));
	if (w == NULL)
		return (NULL);
	w[b - 1] = NULL;
	a = 0;
	while (str[a])
	{
		if (str[a] != ' ' && (a == 0 || str[a - 1] == ' '))
		{
			for (d = 1; str[a + d] != ' ' && str[a + d]; d++)
				;
			d++;
			w[wc] = (char *)malloc(d * sizeof(char));
			d--;
			if (w[wc] == NULL)
			{
				for (e = 0; e < wc; e++)
					free(w[e]);
				free(w[b - 1]);
				free(w);
				return (NULL);
			}
			for (f = 0; f < d; f++)
				w[wc][f] = str[a + f];
			w[wc][f] = '\0';
			wc++;
			a += d;
		}
		else
			a++;
	}
	return (w);
}
