//
// Created by mscheman on 8/22/24.
//

#ifndef EX00_ANIMAL_H
#define EX00_ANIMAL_H

#include "colors.h"
#include <string>
#include <iostream>

class Animal {
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &src);
		Animal& operator = (const Animal &rhs);
		virtual ~Animal();
		virtual void makeSound();
};

#endif //EX00_ANIMAL_H
