#include "function_pointers.h"
/**
 * print_name - A function that prints a name
 * @name: The name to print
 * @f: A function pointer to the printing function
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
