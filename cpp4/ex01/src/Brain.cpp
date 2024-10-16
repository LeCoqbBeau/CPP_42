//
// Created by mscheman on 8/23/24.
//

#include "Brain.h"

Brain::Brain() {

	std::cout << BGRN "Default Brain Constructor called" CLR;
	std::cout << BBLK " [ " << "Brain" << " ]" CLR << std::endl;
}

Brain::~Brain() {
	std::cout << BPRP "Default Brain Destructor called" CLR;
	std::cout << BBLK " [ " << "Brain" << " ]" CLR << std::endl;
}
