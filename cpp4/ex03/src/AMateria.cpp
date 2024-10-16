//
// Created by mscheman on 8/23/24.
//

#include "AMateria.h"

AMateria::AMateria(const std::string &type) {
	this->_type = type;
}

AMateria::~AMateria() {}

const std::string &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter &target) {
	std::cout << BLU "* beats to death " BBLU << target.getName();
	std::cout << BBLU " *" CLR << std::endl;
}

