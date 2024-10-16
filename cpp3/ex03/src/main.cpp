//
// Created by mscheman on 8/16/24.
//

#include "DiamondTrap.h"

int	main()
{
	{
		ScavTrap scavTrap;
		scavTrap.attack("himself");
		ScavTrap copyTrap(scavTrap);
		copyTrap.beRepaired(10);
		ScavTrap assignedTrap("AssignedTrap");
		assignedTrap.takeDamage(5);
		assignedTrap = copyTrap;
		assignedTrap.takeDamage(5);
	}
	std::cout << std::endl;
	{
		ScavTrap bob("Bob");
		ScavTrap jim("Jim");

		bob.attack("Jim");
		for (int i = 0; i < 10; ++i) {
			jim.takeDamage(10);
		}
		jim.attack("Bob");
		bob.beRepaired(15);
		bob.beRepaired(15);
		bob.guardGate();
		for (int i = 0; i < 48; ++i) {
			bob.attack("Jim");
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	{
		FlagTrap flagTrap;
		flagTrap.attack("himself");
		FlagTrap copyTrap(flagTrap);
		copyTrap.beRepaired(10);
		FlagTrap assignedTrap("AssignedTrap");
		assignedTrap.takeDamage(5);
		assignedTrap = copyTrap;
		assignedTrap.takeDamage(5);
	}
	std::cout << std::endl;
	{
		FlagTrap bob("Bob");
		FlagTrap jim("Jim");

		bob.attack("Jim");
		for (int i = 0; i < 10; ++i) {
			jim.takeDamage(10);
		}
		jim.attack("Bob");
		bob.beRepaired(15);
		bob.beRepaired(15);
		bob.highFivesGuys();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	{
		DiamondTrap diamondTrap;
		diamondTrap.attack("himself");
		DiamondTrap copyTrap(diamondTrap);
		copyTrap.beRepaired(10);
		DiamondTrap assignedTrap("AssignedTrap");
		assignedTrap.takeDamage(5);
		assignedTrap = copyTrap;
		assignedTrap.takeDamage(5);
	}
	std::cout << std::endl;
	{
		DiamondTrap bob("Bob");
		DiamondTrap jim("Jim");

		bob.attack("Jim");
		for (int i = 0; i < 10; ++i) {
			jim.takeDamage(10);
		}
		jim.attack("Bob");
		bob.beRepaired(15);
		bob.beRepaired(15);
		bob.guardGate();
		bob.highFivesGuys();
		bob.whoAmI();
		for (int i = 0; i < 48; ++i) {
			bob.attack("Jim");
		}
		bob.guardGate();
		bob.highFivesGuys();
		bob.whoAmI();
		bob.attack("Jim");
	}
}
