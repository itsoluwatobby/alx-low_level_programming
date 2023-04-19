#include "function_pointers.h"

/**
 * print_name - funtion that points to function
 * @name: given parameter
 * @f: function parameter
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
