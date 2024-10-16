#include "WrongAnimal.h"

// Canonical Orthodox Form
WrongAnimal::WrongAnimal() {
	std::cout << BGRN "WrongAnimal Default Constructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
	this->_type = "WrongNone";
}

WrongAnimal::WrongAnimal(const std::string &type) {
	std::cout << BGRN "WrongAnimal Parameterized Constructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
	this->_type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	std::cout << BGRN "WrongAnimal Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << &src << "to" << this << " ] " CLR << std::endl;
	this->_type = src._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
	std::cout << BGRN "WrongAnimal Assignment Operator called" CLR;
	std::cout << BBLK " [ from " << &rhs << "to" << this << " ] " CLR << std::endl;
	this->_type = rhs._type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << BGRN "WrongAnimal Destructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
}

// Methods
void WrongAnimal::makeSound() {
	std::cout << BCYN << _type << CYN ": ..." CLR << std::endl;
}