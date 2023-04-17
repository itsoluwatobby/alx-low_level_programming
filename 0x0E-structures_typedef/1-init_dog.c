#include "dog.h"
#include <stdio.h>

/**
 * init_dog - function that initialize a variable of type struct dog
 * @d: pointer to struct dog
 * @name: pointer to dog's name
 * @age: pointer to dog's age
 * @owner: pointer to the dog's owner
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (!d)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
