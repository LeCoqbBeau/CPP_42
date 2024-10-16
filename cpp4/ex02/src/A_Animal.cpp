//
// Created by mscheman on 8/22/24.
//

#include "A_Animal.h"

A_Animal::A_Animal() {
	_type = "None";
	std::cout << BGRN "Default Abstract_Animal Constructor called" CLR;
	std::cout << BBLK " [ " << _type << " ]" CLR << std::endl;
}

A_Animal::~A_Animal() {
	std::cout << BPRP "Default Abstract_Animal Destructor called" CLR;
	std::cout << BBLK " [ " << _type << " ]" CLR << std::endl;
}

const std::string &A_Animal::getType() const {
	return _type;
}
