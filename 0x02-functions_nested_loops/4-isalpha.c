#include "main.h"
/**
 * _isalpha - checking alphabetical order character
 * @v: Character to be checked
 *
 * Return: 1 or 0
 */
int _isalpha(int v)
{
	if ((v >= 65 && v <= 90) || (v >= 97 && v <= 122))
	{
		return (1);
	}
	return (0);
}
