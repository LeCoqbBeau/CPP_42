//
// Created by mscheman on 8/22/24.
//

#ifndef EX00_ANIMAL_H
#define EX00_ANIMAL_H

#include "colors.h"
#include <string>
#include <iostream>

class A_Animal {
	protected:
		std::string _type;
	public:
		A_Animal();
		virtual ~A_Animal();
		virtual void makeSound() = 0;
		const std::string &getType() const;
};

#endif //EX00_ANIMAL_H
