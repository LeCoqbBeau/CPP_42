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
		virtual ~Animal();
		virtual void makeSound();
		const std::string &getType() const;
};

#endif //EX00_ANIMAL_H
