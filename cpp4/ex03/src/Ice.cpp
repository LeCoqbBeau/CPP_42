//
// Created by mscheman on 8/23/24.
//

#include "Ice.h"

Ice::Ice() : AMateria("ice") {}

AMateria *Ice::clone() const {
	return new Ice;
}

void Ice::use(ICharacter &target) {
	std::cout << CYN "* shoots an ice bolt at " BCYN;
	std::cout << target.getName() << CYN " *" CLR << std::endl;
}
