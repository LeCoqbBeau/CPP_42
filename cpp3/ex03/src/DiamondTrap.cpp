//
// Created by mscheman on 8/22/24.
//

#include "DiamondTrap.h"

DiamondTrap::DiamondTrap() : ScavTrap(),
							 FlagTrap() {
	std::cout << BGRN "DiamondTrap Default Constructor called" CLR;
	std::cout << BBLK " [ " << CLAPTRAP_NAME << " ]" CLR << std::endl;
	this->DiamondTrap::_name = CLAPTRAP_NAME;
	this->setName(this->DiamondTrap::_name + "_clap_name");
	this->setHealthPoints(DIAMONDTRAP_HP);
	this->setEnergyPoints(DIAMONDTRAP_EP);
	this->setAttackDamage(DIAMONDTRAP_AD);
}

DiamondTrap::DiamondTrap(const std::string &name) : ScavTrap(name),
													FlagTrap(name) {
	std::cout << BGRN "DiamondTrap Parameterized Constructor called" CLR;
	std::cout << BBLK " [ " << name << " ]" CLR << std::endl;
	this->DiamondTrap::_name = name;
	this->setName(name + "_clap_name");
	this->setHealthPoints(DIAMONDTRAP_HP);
	this->setEnergyPoints(DIAMONDTRAP_EP);
	this->setAttackDamage(DIAMONDTRAP_AD);
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) :  ScavTrap(),
													FlagTrap() {
	std::cout << BGRN "DiamondTrap Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << src.DiamondTrap::_name << " ]" CLR << std::endl;
	this->DiamondTrap::_name = CLAPTRAP_NAME;
	this->setName(_name + "_clap_name");
	this->setHealthPoints(src.getHealthPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setAttackDamage(src.getAttackDamage());
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
	std::cout << BGRN "DiamondTrap Assignment Operator called" CLR;
	std::cout << BBLK " [ from " << this->DiamondTrap::_name << " to " << rhs.DiamondTrap::_name << " ]" CLR << std::endl;
	this->DiamondTrap::_name = rhs.DiamondTrap::_name;
	this->setName(this->DiamondTrap::_name + "_clap_name");
	this->setHealthPoints(rhs.getHealthPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << BPRP "DiamondTrap Destructor called" CLR;
	std::cout << BBLK " [ " << this->DiamondTrap::_name << " ]" CLR << std::endl;
}

void DiamondTrap::whoAmI() {
	if (getHealthPoints() == 0)
	{
		std::cout << RED "DiamondTrap " BRED << this->DiamondTrap::_name << RED " is dead.";
		std::cout << CLR << std::endl;
		return ;
	}
	if (getEnergyPoints() == 0)
	{
		std::cout << YLW "DiamondTrap " BYLW << this->DiamondTrap::_name << YLW " doesn't have ";
		std::cout << "to ask questions..." CLR << std::endl;
		return ;
	}
	std::cout << CYN "I am " BCYN << _name;
	std::cout << CYN " and also " BCYN << getName() << CLR << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}
