//
// Created by mscheman on 8/16/24.
//

#include "ScavTrap.h"

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
}
