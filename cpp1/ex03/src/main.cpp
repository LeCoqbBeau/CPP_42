//
// Created by mscheman on 8/19/24.
//

#include <HumanA.h>
#include <HumanB.h>
#include <Weapon.h>

int main()
{
	Weapon stick = Weapon("stick");
	Weapon rock = Weapon("rock");
	Weapon gunblade = Weapon("gun");

	HumanA bob("Bob", gunblade);
	HumanB jim("Jim");

	bob.attack();
	jim.attack();
	jim.setWeapon(&stick);
	jim.attack();
	jim.setWeapon(&rock);
	jim.attack();
	gunblade.setType("blade");
	bob.attack();
}