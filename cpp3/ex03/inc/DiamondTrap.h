//
// Created by mscheman on 8/22/24.
//

#ifndef EX03_DIAMONDTRAP_H
#define EX03_DIAMONDTRAP_H

#include "ScavTrap.h"
#include "FlagTrap.h"

#define DIAMONDTRAP_HP FLAGTRAP_HP
#define DIAMONDTRAP_EP SCAVTRAP_EP
#define DIAMONDTRAP_AD FLAGTRAP_AD

class DiamondTrap : public ScavTrap, public FlagTrap {
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap &src);
		DiamondTrap& operator = (const DiamondTrap &rhs);
		~DiamondTrap();
		virtual void attack(const std::string &target);
		void	whoAmI();
};


#endif //EX03_DIAMONDTRAP_H
