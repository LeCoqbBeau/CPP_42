//
// Created by mscheman on 8/19/24.
//

#include "Weapon.h"

Weapon::Weapon(const std::string &type) {
	this->_type = type;
}

const std::string &Weapon::getType() {
	return this->_type;
}

void Weapon::setType(const std::string &type) {
	this->_type = type;
}

