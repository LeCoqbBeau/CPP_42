//
// Created by mscheman on 8/22/24.
//

#ifndef EX01_SCAVTRAP_H
#define EX01_SCAVTRAP_H

#include "ClapTrap.h"

#define SCAVTRAP_HP 100
#define SCAVTRAP_EP 50
#define SCAVTRAP_AD 20

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap &src);
		ScavTrap& operator = (const ScavTrap &rhs);
		~ScavTrap();
		void attack(const std::string &target);
		void guardGate();
};


#endif //EX01_SCAVTRAP_H
