//
// Created by mscheman on 8/19/24.
//

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
	public:
		const std::string	&getType();
		void				setType(const std::string& type);
		Weapon(const std::string &type);
	private:
		std::string	_type;
};

#endif
