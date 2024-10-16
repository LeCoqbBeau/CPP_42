//
// Created by mscheman on 8/22/24.
//

#ifndef EX00_CLAPTRAP_H
#define EX00_CLAPTRAP_H

#include "colors.h"
#include <iostream>
#include <string>

#define CLAPTRAP_NAME "Default"
#define CLAPTRAP_HP 10
#define CLAPTRAP_EP 10
#define CLAPTRAP_AD 0

class ClapTrap {
	private:
		std::string		_name;
		unsigned int	_healthPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &src);
		ClapTrap &operator = (const ClapTrap &rhs);
		~ClapTrap();

		virtual void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	protected:
		const std::string &getName() const;
		unsigned int getHealthPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;
		void setName(const std::string &name);
		void setHealthPoints(unsigned int healthPoints);
		void setEnergyPoints(unsigned int energyPoints);
		void setAttackDamage(unsigned int attackDamage);
};

#endif //EX00_CLAPTRAP_H
