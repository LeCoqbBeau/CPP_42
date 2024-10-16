//
// Created by mscheman on 8/22/24.
//

#include "Animal.h"

Animal::Animal() {
	_type = "None";
	std::cout << BGRN "Default Animal Constructor called" CLR;
	std::cout << BBLK " [ " << _type << " ]" CLR << std::endl;
}

Animal::~Animal() {
	std::cout << BPRP "Default Animal Destructor called" CLR;
	std::cout << BBLK " [ " << _type << " ]" CLR << std::endl;
}

void Animal::makeSound() {
	std::cout << BCYN << _type << CYN ": ..." CLR << std::endl;
}

const std::string &Animal::getType() const {
	return _type;
}
