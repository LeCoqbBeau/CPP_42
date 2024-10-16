//
// Created by mscheman on 8/19/24.
//

#include <Zombie.h>

Zombie *newZombie( std::string name )
{
	Zombie *summoned;

	summoned = new Zombie(name);
	return (summoned);
}
