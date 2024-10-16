//
// Created by mscheman on 8/19/24.
//

#include "HumanA.h"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _weapon(weapon) {
	this->_name = name;
}

void HumanA::attack() {
	std::cout << BCYN << _name << CYN " attacks with their ";
	std::cout << BCYN << _weapon.getType() << CLR << std::endl;
}
