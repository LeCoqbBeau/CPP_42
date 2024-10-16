#ifndef DOG_H
# define DOG_H

# include <iostream>
# include "colors.h"

#include "Animal.h"

class Dog : public Animal
{
public:
	// Orthodox Canonical Form
	Dog();
	Dog(const Dog &src);
	Dog &operator=(const Dog &rhs);
	~Dog();

	// Methods
	void makeSound();
};

#endif //DOG
