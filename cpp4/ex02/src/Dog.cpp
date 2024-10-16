//
// Created by mscheman on 8/22/24.
//

#include "Dog.h"

Dog::Dog() : A_Animal() {
	this->_type = "Dog";
	this->_brain = new Brain;
	std::cout << BGRN "Default Dog Constructor called" CLR;
	std::cout << BBLK " [ " << _type << " ]" CLR << std::endl;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << BPRP "Default Dog Destructor called" CLR;
	std::cout << BBLK " [ " << _type << " ]" CLR << std::endl;
}

void Dog::makeSound() {
	std::cout << BCYN << _type << CYN ": woof" CLR << std::endl;
}
