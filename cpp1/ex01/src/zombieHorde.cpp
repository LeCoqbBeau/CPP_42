//
// Created by mscheman on 8/19/24.
//

#include <Zombie.h>

Zombie *zombieHorde( int N, std::string name )
{
	Zombie *horde;

	if (N < 0)
	{
		std::cout << BYLW "Flag zombie skipped math class..." << std::endl;
		return (__nullptr);
	}
	horde = new Zombie[N];
	if (!horde)
		return (0);
	for (int i = 0; i < N; ++i) {
		horde[i].set_name(name);
	}
	return (horde);
}
