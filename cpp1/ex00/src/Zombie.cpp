//
// Created by mscheman on 8/19/24.
//

#include <colors.h>
#include <Zombie.h>

Zombie::Zombie() {
	this->_name = "Dr. Zomboss";
}

Zombie::Zombie(const std::string &name) {
	this->_name = name;
}

void Zombie::announce(void) {
	std::cout << BRED << this->_name << RED ": BraiiiiiiinnnzzzZ..." CLR << std::endl;
}

Zombie::~Zombie() {
	std::cout << BPRP << this->_name << " ";
	if (this->_name == "Dr. Zomboss")
		std::cout << PRP "escaped once again..." CLR << std::endl;
	else
		std::cout << PRP "got shot by a peashooter" CLR << std::endl;
}
