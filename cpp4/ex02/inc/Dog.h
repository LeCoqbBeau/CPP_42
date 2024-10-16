//
// Created by mscheman on 8/22/24.
//

#ifndef EX00_DOG_H
#define EX00_DOG_H

#include "A_Animal.h"
#include "Brain.h"

class Dog : public A_Animal {
	private:
		Brain *_brain;
	public:
		Dog();
		~Dog();
		void makeSound();
};


#endif //EX00_DOG_H
