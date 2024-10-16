//
// Created by mscheman on 8/22/24.
//

#include "ScavTrap.h"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << BGRN "ScavTrap Default Constructor called" CLR;
	std::cout << BBLK " [ " << CLAPTRAP_NAME << " ]" CLR << std::endl;
	this->setHealthPoints(SCAVTRAP_HP);
	this->setEnergyPoints(SCAVTRAP_EP);
	this->setAttackDamage(SCAVTRAP_AD);
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cout << BGRN "ScavTrap Parameterized Constructor called" CLR;
	std::cout << BBLK " [ " << name << " ]" CLR << std::endl;
	this->setHealthPoints(SCAVTRAP_HP);
	this->setEnergyPoints(SCAVTRAP_EP);
	this->setAttackDamage(SCAVTRAP_AD);
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src.getName()) {
	std::cout << BGRN "ScavTrap Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << src.getName() << " ]" CLR << std::endl;
	this->setName(src.getName());
	this->setHealthPoints(src.getHealthPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setAttackDamage(src.getAttackDamage());
}

ScavTrap &ScavTrap::operator = (const ScavTrap &rhs) {
	std::cout << BGRN "ScavTrap Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << this->getName() << " to " << rhs.getName() << " ]" CLR << std::endl;
	this->setName(rhs.getName());
	this->setHealthPoints(rhs.getHealthPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << BPRP "ScavTrap Destructor called" CLR;
	std::cout << BBLK " [ " << getName() << " ]" CLR << std::endl;
}

void ScavTrap::guardGate() {
	if (getHealthPoints() == 0)
	{
		std::cout << RED "ScavTrap " BRED << getName() << RED " is dead.";
		std::cout << CLR << std::endl;
		return ;
	}
	if (getEnergyPoints() == 0)
	{
		std::cout << YLW "ScavTrap " BYLW << getName() << YLW " doesn't have ";
		std::cout << "enough change mode." CLR << std::endl;
		return ;
	}
	std::cout << CYN "ScavTrap " BCYN << getName() << CYN " is now in Gate keeper mode ";
	std::cout << CLR << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (getHealthPoints() == 0)
	{
		std::cout << RED "ScavTrap " BRED << getName() << RED " is dead.";
		std::cout << CLR << std::endl;
		return ;
	}
	if (getEnergyPoints() == 0)
	{
		std::cout << YLW "ScavTrap " BYLW << getName() << YLW " doesn't have ";
		std::cout << "enough energy to attack." CLR << std::endl;
		return ;
	}
	std::cout << CYN "ScavTrap " BCYN << getName() << CYN " attacks " BCYN;
	std::cout << target << CYN ", causing " BCYN << getAttackDamage();
	std::cout << CYN " damage.";
	std::cout << YLW " [ " << getEnergyPoints() << "ep -> " << (getEnergyPoints() - 1) << "ep ]" CLR << std::endl;
	setEnergyPoints(getEnergyPoints() - 1);
	if (!getEnergyPoints())
		std::cout << YLW "ScavTrap " BYLW << getName() << YLW " broke down." CLR << std::endl;
}
