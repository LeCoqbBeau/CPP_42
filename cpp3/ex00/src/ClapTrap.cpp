//
// Created by mscheman on 8/22/24.
//

#include "ClapTrap.h"

ClapTrap::ClapTrap() {
	std::cout << BGRN "ClapTrap Default Constructor called" CLR;
	std::cout << BBLK " [ " << CLAPTRAP_NAME << " ]" CLR << std::endl;
	this->_name = CLAPTRAP_NAME;
	this->_healthPoints = CLAPTRAP_HP;
	this->_energyPoints = CLAPTRAP_EP;
	this->_attackDamage = CLAPTRAP_AD;
}

ClapTrap::ClapTrap(const std::string &name) {
	std::cout << BGRN "ClapTrap Parameterized Constructor called" CLR;
	std::cout << BBLK " [ " << name << " ]" CLR << std::endl;
	this->_name = name;
	this->_healthPoints = CLAPTRAP_HP;
	this->_energyPoints = CLAPTRAP_EP;
	this->_attackDamage = CLAPTRAP_AD;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << BGRN "ClapTrap Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << src._name << " ]" CLR << std::endl;
	this->_name = src._name;
	this->_healthPoints = src._healthPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._energyPoints;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &rhs) {
	std::cout << BGRN "ClapTrap Assignment Operator called" CLR;
	std::cout << BBLK " [ from " << this->_name << " to " << rhs._name << " ]" CLR << std::endl;
	this->_name = rhs._name;
	this->_healthPoints = rhs._healthPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._energyPoints;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << BPRP "ClapTrap Destructor called" CLR;
	std::cout << BBLK " [ " << this->_name << " ]" CLR << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (this->_healthPoints == 0)
	{
		std::cout << RED "ClapTrap " BRED << this->_name << RED " is dead.";
		std::cout << CLR << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << YLW "ClapTrap " BYLW << this->_name << YLW " doesn't have ";
		std::cout << "enough energy to attack." CLR << std::endl;
		return ;
	}
	std::cout << CYN "ClapTrap " BCYN << this->_name << CYN " attacks " BCYN;
	std::cout << target << CYN ", causing " BCYN << this->_attackDamage;
	std::cout << CYN " damage.";
	std::cout << YLW " [ " << _energyPoints << "ep -> " << (_energyPoints - 1) << "ep ]" CLR << std::endl;
	this->_energyPoints--;
	if (!this->_energyPoints)
		std::cout << YLW "ClapTrap " BYLW << this->_name << YLW " broke down." CLR << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_healthPoints == 0)
	{
		std::cout << RED "ClapTrap " BRED << this->_name << RED " is already dead.";
		std::cout << CLR << std::endl;
		return ;
	}
	std::cout << BLU "ClapTrap " BBLU << this->_name << BLU " took " BBLU;
	std::cout << amount << " damage.";
	std::cout << PRP " [ " << _healthPoints << "hp -> " << (_healthPoints - amount) * (_healthPoints > amount) << "hp ]" CLR << std::endl;
	if (amount >= _healthPoints)
	{
		std::cout << RED "ClapTrap " BRED << this->_name << RED " died.";
		std::cout << CLR << std::endl;
		_healthPoints = 0;
		return ;
	}
	_healthPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_healthPoints == 0)
	{
		std::cout << RED "ClapTrap " BRED << this->_name << RED " is dead.";
		std::cout << CLR << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << YLW "ClapTrap " BYLW << this->_name << YLW " doesn't have ";
		std::cout << "enough energy to repair itself." CLR << std::endl;
		return ;
	}
	std::cout << CYN "ClapTrap " BCYN << this->_name << CYN " repairs itself by " BCYN;
	std::cout << amount << CYN " health points." CLR;
	std::cout << PRP " [ " << _healthPoints << "hp -> " << (_healthPoints + amount) << "hp ]" CLR;
	std::cout << YLW " [ " << _energyPoints << "ep -> " << (_energyPoints - 1) << "ep ]" CLR << std::endl;
	_healthPoints += amount;
	this->_energyPoints--;
	if (!this->_energyPoints)
		std::cout << YLW "ClapTrap " BYLW << this->_name << YLW " broke down." CLR << std::endl;
}
