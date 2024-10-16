//
// Created by mscheman on 8/22/24.
//

#include "Animal.h"

Animal::Animal() {
	std::cout << BGRN "Animal Default Constructor called" CLR;
	std::cout << BBLK " [ " << _type << " ]" CLR << std::endl;
	_type = "None";
}

Animal::Animal(const std::string &type) {
	std::cout << BGRN "Animal Parameterized Constructor called" CLR;
	std::cout << BBLK " [ " << _type << " ]" CLR << std::endl;
	_type = type;
}

Animal::Animal(const Animal &src) {
	std::cout << BGRN "Animal Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << src._type << " ]" CLR << std::endl;
	_type = src._type;
}

Animal& Animal::operator = (const Animal &rhs)
{
	std::cout << BGRN "Animal Assignment Operator called" CLR;
	std::cout << BBLK " [ from " << this->_type << " to " << rhs._type << " ]" CLR << std::endl;
	_type = rhs._type;
	return *this;
}

Animal::~Animal() {
	std::cout << BPRP "Default Animal Destructor called" CLR;
	std::cout << BBLK " [ " << _type << " ]" CLR << std::endl;
}

void Animal::makeSound() {
	std::cout << BCYN << _type << CYN ": ..." CLR << std::endl;
}
