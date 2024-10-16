#include "Cat.h"

// Canonical Orthodox Form
Cat::Cat() : Animal("Cat") {
	std::cout << BGRN "Cat Default Constructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << BGRN "Cat Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << &src << "to" << this << " ] " CLR << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
	std::cout << BGRN "Cat Assignment Operator called" CLR;
	std::cout << BBLK " [ from " << &rhs << "to" << this << " ] " CLR << std::endl;
	this->_type = rhs._type;
	return *this;
}

Cat::~Cat() {
	std::cout << BGRN "Cat Destructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
}

// Methods
void Cat::makeSound() {
	std::cout << BCYN << _type << CYN ": meow" CLR << std::endl;
}