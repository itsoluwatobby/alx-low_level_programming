#include "dog.h"
#include <stdlib.h>

/**
 * _strcpy - function that copies a string
 * @str: given string
 * @dest: copy of the given string
 * Return: dest
 */

char *_strcpy(char *dest, char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
		dest[i] = str[i];

	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - finds the length of a string
 * @targ: given string
 * Return: length
 */

int _strlen(char *targ)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}

/**
 * new_dog - function that creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: owner of the dog
 * Return: new type of dog
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dogs;

	if (name == NULL || age < 0 || owner == NULL)
		return (NULL);

	dogs = malloc(sizeof(dog_t));

	if (dogs == NULL)
		return (NULL);

	dogs->name = malloc(sizeof(char) * (_strlen(name) + 1));

	if (dogs->name == NULL)
	{
		free(dogs);
		return (NULL);
	}

	dogs->owner = malloc(sizeof(char) * (_strlen(owner) + 1));

	if (dogs->owner == NULL)
	{
		free(dogs->name);
		free(dogs);
		return (NULL);
	}

	_strcpy(dogs->name, name);
	_strcpy(dogs->owner, owner);
	dogs->age = age;

	return (dogs);
}
