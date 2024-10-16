//
// Created by mscheman on 8/22/24.
//

#include "Cat.h"

Cat::Cat() : A_Animal() {
	this->_type = "Cat";
	this->_brain = new Brain;
	std::cout << BGRN "Default Cat Constructor called" CLR;
	std::cout << BBLK " [ " << _type << " ]" CLR << std::endl;
}

Cat::~Cat() {
	delete _brain;
	std::cout << BPRP "Default Cat Destructor called" CLR;
	std::cout << BBLK " [ " << _type << " ]" CLR << std::endl;
}

void Cat::makeSound() {
	std::cout << BCYN << _type << CYN ": meow" CLR << std::endl;
}
