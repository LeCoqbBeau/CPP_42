//
// Created by mscheman on 8/19/24.
//

#include <Zombie.h>

int main()
{
	Zombie zomboss;
	Zombie *gargantua = newZombie("Gargantua");
	Zombie imp("imp");

	zomboss.announce();
	gargantua->announce();
	imp.announce();
	randomChump("Yeti");
	delete gargantua;
}