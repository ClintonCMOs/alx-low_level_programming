#include "dog.h"
#include <string.h>
#include <stdlib.h>

/**
 * new_dog - Creates a new dog with the specified attributes.
 * @name: Name of the dog.
 * @age: Age of the dog.
 * @owner: Owner of the dog.
 *
 * Return: Pointer to the newly created dog or NULL (when malloc fails).
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog_ptr;

	new_dog_ptr = (dog_t *)malloc(sizeof(dog_t));
	if (new_dog_ptr == NULL)
	{
		return (NULL);
	}
	new_dog_ptr->name = (char *)malloc(strlen(name) + 1);
	new_dog_ptr->owner = (char *)malloc(strlen(owner) + 1);
	if (new_dog_ptr->name == NULL || new_dog_ptr->owner == NULL)
	{
		free(new_dog_ptr->name);
		free(new_dog_ptr->owner);
		free(new_dog_ptr);
		return (NULL);
	}
	strcpy(new_dog_ptr->name, name);
	strcpy(new_dog_ptr->owner, owner);
	new_dog_ptr->age = age;
	return (new_dog_ptr);
}
