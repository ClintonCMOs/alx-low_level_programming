#include "dog.h"
#include <stdlib.h>
/**
 * init_dog - Initializes a struct dog
 * @d: pointer to struct dog to initialize
 * @name: Name to set
 * @age: Age to set
 * @owner: owner to set
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
