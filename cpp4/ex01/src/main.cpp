//
// Created by mscheman on 8/16/24.
//

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

#define ARRAY_SIZE 5

int	main()
{
	Animal *animals[ARRAY_SIZE];

	for (int i = 0; i < ARRAY_SIZE; ++i) {
		if (i % 2)
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
		animals[i]->makeSound();
	}
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		delete animals[i];
	}
	return 0;
}
