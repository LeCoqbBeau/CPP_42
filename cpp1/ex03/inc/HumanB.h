//
// Created by mscheman on 8/19/24.
//

#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include "Weapon.h"
#include "colors.h"

class HumanB {
	private:
		std::string	_name;
		Weapon		*_weapon;
	public:
		HumanB(const std::string &name);
		void setWeapon(Weapon *weapon);
		void attack();
};


#endif
