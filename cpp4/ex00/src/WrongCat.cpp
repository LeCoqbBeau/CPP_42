#include "WrongCat.h"

// Canonical Orthodox Form
WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << BGRN "WrongCat Default Constructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
	std::cout << BGRN "WrongCat Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << &src << "to" << this << " ] " CLR << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
	std::cout << BGRN "WrongCat Assignment Operator called" CLR;
	std::cout << BBLK " [ from " << &rhs << "to" << this << " ] " CLR << std::endl;
	this->_type = rhs._type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << BGRN "WrongCat Destructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
}

// Methods
void WrongCat::makeSound() {
	std::cout << BCYN << _type << CYN ": wrong meow" CLR << std::endl;
}