#include "main.h"

/**
 * inspect_strlen - function to return length of string
 * @s: string to check
 *
 * Return: length of s
 */
int inspect_strlen(char *s)
{
	if (*s == '\0')
		return (0);
	else
		return (1 + inspect_strlen(s + 1));
}

/**
 * inspect_palindrome - checks to see if a string is a palindrome
 * @str: string to check
 * @len: length of string
 * @p: possible palindrome
 *
 * Return: 1 if palindrome ,else 0
 */
int inspect_palindrome(int str, int len, char *p)
{
	if (str >= len)
		return (1);
	else if (p[str] != p[len])
		return (0);
	else
		return (inspect_palindrome(str + 1, len - 1, p));
}

/**
 * is_palindrome - states if a string is a palindrome
 * @s: string to check
 *
 * Return: 1 if palindrome, else 0
 */
int is_palindrome(char *s)
{
	int i;

	i = inspect_strlen(s) - 1;
	return (inspect_palindrome(0, i, s));
}
