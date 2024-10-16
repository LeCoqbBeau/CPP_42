//
// Created by mscheman on 8/23/24.
//

#include "Cure.h"

Cure::Cure() : AMateria("cure") {}

AMateria *Cure::clone() const {
	return new Cure;
}

void Cure::use(ICharacter &target) {
	std::cout << GRN "* heals " BGRN << target.getName();
	std::cout  << GRN "'s wounds *" CLR << std::endl;
}
