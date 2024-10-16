//
// Created by mscheman on 8/16/24.
//

#include "ClapTrap.h"

int	main()
{
	{
		ClapTrap clapTrap;
		clapTrap.attack("himself");
		ClapTrap copyTrap(clapTrap);
		copyTrap.beRepaired(10);
		ClapTrap assignedTrap("AssignedTrap");
		assignedTrap.takeDamage(5);
		assignedTrap = copyTrap;
		assignedTrap.takeDamage(5);
	}
	{
		ClapTrap bob("Bob");
		ClapTrap jim("Jim");

		bob.attack("Jim");
		for (int i = 0; i < 10; ++i) {
			jim.takeDamage(1);
		}
		jim.beRepaired(10);
		bob.beRepaired(15);
		bob.beRepaired(15);
		for (int i = 0; i < 8; ++i) {
			bob.attack("Jim");
		}
	}
}
