#include "Dog.h"

// Canonical Orthodox Form
Dog::Dog() : Animal("Dog") {
	std::cout << BGRN "Dog Default Constructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << BGRN "Dog Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << &src << "to" << this << " ] " CLR << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
	std::cout << BGRN "Dog Assignment Operator called" CLR;
	std::cout << BBLK " [ from " << &rhs << "to" << this << " ] " CLR << std::endl;
	this->_type = rhs._type;
	return *this;
}

Dog::~Dog() {
	std::cout << BGRN "Dog Destructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
}

// Methods
void Dog::makeSound() {
	std::cout << BCYN << _type << CYN ": woof" CLR << std::endl;
}