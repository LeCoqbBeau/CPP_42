//
// Created by mscheman on 8/22/24.
//

#ifndef EX00_WRONGANIMAL_H
#define EX00_WRONGANIMAL_H

#include "colors.h"
#include <string>
#include <iostream>

class WrongAnimal {
	protected:
		std::string _type;
	public:
		WrongAnimal();
		~WrongAnimal();
		void makeSound();

		const std::string &getType() const;
};


#endif //EX00_WRONGANIMAL_H
