//
// Created by mscheman on 8/19/24.
//

#include "HumanB.h"

HumanB::HumanB(const std::string &name) {
	this->_name = name;
	this->_weapon = __nullptr;
}

void HumanB::setWeapon(Weapon *weapon) {
	this->_weapon = weapon;
}

void HumanB::attack() {
	if (_weapon)
	{
		std::cout << BRED << _name << RED " attacks with their ";
		std::cout << BRED << _weapon->getType() << CLR << std::endl;
	}
	else
	{
		std::cout << BYLW << _name << YLW " forgor to bring a weapon... ";
		std::cout << BYLW << "...he's getting his ass kicked for sure!" << CLR << std::endl;
	}
}
