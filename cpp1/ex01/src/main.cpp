//
// Created by mscheman on 8/19/24.
//

#include <Zombie.h>

int main()
{
	Zombie zomboss;
	Zombie flag("Flag Zombie");
	Zombie *horde;

	zomboss.announce();
	flag.announce();
	horde = zombieHorde(-15, "Classic Zombie");
	horde = zombieHorde(3, "Classic Zombie");
	for (int i = 0; i < 3; ++i) {
		horde[i].announce();
	}
	delete[] horde;
}