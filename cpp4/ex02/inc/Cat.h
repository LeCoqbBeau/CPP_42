//
// Created by mscheman on 8/22/24.
//

#ifndef EX00_CAT_H
#define EX00_CAT_H

#include "A_Animal.h"
#include "Brain.h"

class Cat : public A_Animal {
	private:
		Brain *_brain;
	public:
		Cat();
		~Cat();
		void makeSound();
};


#endif //EX00_CAT_H
