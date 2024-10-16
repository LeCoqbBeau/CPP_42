//
// Created by mscheman on 8/22/24.
//

#include "FlagTrap.h"

FlagTrap::FlagTrap() : ClapTrap() {
	std::cout << BGRN "FlagTrap Default Constructor called" CLR;
	std::cout << BBLK " [ " << CLAPTRAP_NAME << " ]" CLR << std::endl;
	this->setHealthPoints(FLAGTRAP_HP);
	this->setEnergyPoints(FLAGTRAP_EP);
	this->setAttackDamage(FLAGTRAP_AD);
}

FlagTrap::FlagTrap(const std::string &name) : ClapTrap(name) {
	std::cout << BGRN "FlagTrap Parameterized Constructor called" CLR;
	std::cout << BBLK " [ " << name << " ]" CLR << std::endl;
	this->setHealthPoints(FLAGTRAP_HP);
	this->setEnergyPoints(FLAGTRAP_EP);
	this->setAttackDamage(FLAGTRAP_AD);
}

FlagTrap::FlagTrap(const FlagTrap &src) : ClapTrap() {
	std::cout << BGRN "FlagTrap Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << src.getName() << " ]" CLR << std::endl;
	this->setName(src.getName());
	this->setHealthPoints(src.getHealthPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setAttackDamage(src.getAttackDamage());
}

FlagTrap &FlagTrap::operator=(const FlagTrap &rhs) {
	std::cout << BGRN "FlagTrap Assignment Operator called" CLR;
	std::cout << BBLK " [ from " << this->getName() << " to " << rhs.getName() << " ]" CLR << std::endl;
	this->setName(rhs.getName());
	this->setHealthPoints(rhs.getHealthPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	return *this;
}

FlagTrap::~FlagTrap() {
	std::cout << BPRP "FlagTrap Destructor called" CLR;
	std::cout << BBLK " [ " << getName() << " ]" CLR << std::endl;
}

void FlagTrap::highFivesGuys(void) {
	if (getHealthPoints() == 0)
	{
		std::cout << RED "FlagTrap " BRED << getName() << RED " is dead.";
		std::cout << CLR << std::endl;
		return ;
	}
	if (getEnergyPoints() == 0)
	{
		std::cout << YLW "FlagTrap " BYLW << getName() << YLW " doesn't have ";
		std::cout << "enough energy to high five..." CLR << std::endl;
		return ;
	}
	std::cout << CYN "FlagTrap " BCYN << getName() << CYN " is doing a high five!";
	std::cout << CLR << std::endl;
}
