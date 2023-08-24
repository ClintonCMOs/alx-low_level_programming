#include "main.h"
/**
 * rot13 - A function that encrypts code
 * @s: string to be encrypted
 * Return: char
 */
char *rot13(char *s)
{
	char part1[52] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
	char part2[52] = "nNoOpPqQrRsStTuUvVwWxXyYzZaAbBcCdDeEfFgGhHiIjJkKlLmM";

	int i;
	int j = 0;

	for (i = 0; s[i] != '\0'; i++)
	{

		for (j = 0; part1[j] != '\0'; j++)
		{
			if (s[i] == part1[j])
			{
				s[i] = part2[j];
				break;
			}
		}
	}
	return (s);
}
