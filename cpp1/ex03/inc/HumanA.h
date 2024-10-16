//
// Created by mscheman on 8/19/24.
//

#ifndef HUMANA_H
#define HUMANA_H

#include <iostream>
#include "Weapon.h"
#include "colors.h"

class HumanA {
	public:
		HumanA(const std::string &name, Weapon &weapon);
		void attack();
	private:
		std::string _name;
		Weapon		&_weapon;
};


#endif
