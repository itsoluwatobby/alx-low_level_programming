#include "lists.h"
#include <stdio.h>

void print_before_main(void) __attribute__((constructor))

/**
 * print_before_main - a function that runs before the main funtion
 */

void print_before_main(void)
{
	printf("You're beat! and yet, you must allow,\n
			I bore my house upon my back!\n");
}
