#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/**
  *print_all - The function that prints anything
  *
  *@format: Arguments passed to the function
  *
  *@...: variable number of arguments
  */
void print_all(const char * const format, ...)
{
	char *str;
	unsigned int a = 0;
	va_list args;

	va_start(args, format);
	while (format == NULL)
	{
		printf("\n");
		return;
	}
	while (format[a] != '\0')
	{
		switch (format[a])
		{
			case 'c':
				printf("%c", (char)va_arg(args, int));
				break;
			case 'i':
			  printf("%d", va_arg(args, int));
					break;
			case 'f':
				printf("%f", (float)va_arg(args, double));
				break;
			case 's':
				str = va_arg(args, char*);
				if (str != NULL)
				{
					printf("%s", str);
					break;
				}
				printf("(nil)");
				break;

		}
		if ((format[a] == 'c' || format[a] == 'i' || format[a] == 'f' ||
		     format[a] == 's') && format[a + 1] != '\0')
			printf(", ");
		a++;
	}
	printf("\n"), va_end(args);
}
