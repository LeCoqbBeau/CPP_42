//
// Created by mscheman on 8/22/24.
//

#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() {
	_type = "WrongNone";
	std::cout << BGRN "Default WrongAnimal Constructor called" CLR;
	std::cout << BBLK " [ " << _type << " ]" CLR << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << BPRP "Default WrongAnimal Destructor called" CLR;
	std::cout << BBLK " [ " << _type << " ]" CLR << std::endl;
}

void WrongAnimal::makeSound() {
	std::cout << BCYN << _type << CYN ": wrong ..." CLR << std::endl;
}

const std::string &WrongAnimal::getType() const {
	return _type;
}
