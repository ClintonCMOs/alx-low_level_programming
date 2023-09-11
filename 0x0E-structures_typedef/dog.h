#ifndef DOG_H
#define DOG_H

/**
 * struct dog - A new type with 3 elements
 * @name: my dog's name
 * @age: my dog's age in years
 * @owner: Dog owner
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
typedef struct dog dog_t;
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif /*DOG_H*/
