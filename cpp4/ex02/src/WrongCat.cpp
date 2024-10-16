//
// Created by mscheman on 8/22/24.
//

#include "WrongCat.h"

WrongCat::WrongCat() : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << BGRN "Default WrongCat Constructor called" CLR;
	std::cout << BBLK " [ " << _type << " ]" CLR << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << BPRP "Default WrongCat Destructor called" CLR;
	std::cout << BBLK " [ " << _type << " ]" CLR << std::endl;
}

void WrongCat::makeSound() {
	std::cout << BCYN << _type << CYN ": wrong meow" CLR << std::endl;
}
