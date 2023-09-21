#include <stdio.h>

void startup_function(void) __attribute__((constructor));
/**
 * startup_function - Function that runs before main.
 */
void startup_function(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
