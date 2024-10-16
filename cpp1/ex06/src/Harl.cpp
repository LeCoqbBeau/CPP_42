//
// Created by mscheman on 8/20/24.
//

#include "Harl.h"

static void incorrect_level();

void Harl::complain(std::string level) {
	int	i;

	i = -1;
	if (level == "DEBUG")
		i = 0;
	if (level == "INFO")
		i = 1;
	if (level == "WARNING")
		i = 2;
	if (level == "ERROR")
		i = 3;
	switch (i) {
		case 0:
			_debug();
		case 1:
			_info();
		case 2:
			_warning();
		case 3:
			_error();
			break;
		default:
			incorrect_level();
	}
}

static void incorrect_level()
{
	std::cout << BPRP;
	std::cout << "How could you guess that I don't take any showers ?";
	std::cout << CLR << std::endl;
}

void Harl::_debug() {
	std::cout << BCYN;
	std::cout << "I love playing league of legend!";
	std::cout << CLR << std::endl;
}

void Harl::_info() {
	std::cout << BGRN;
	std::cout << "I play top lane and really like to split push, that's why I play Tryndamere.";
	std::cout << CLR << std::endl;
}

void Harl::_warning() {
	std::cout << BYLW;
	std::cout << "My jungler still hasn't ganked me once whereas they ganked me twice...";
	std::cout << CLR << std::endl;
}

void Harl::_error() {
	std::cout << BRED;
	std::cout << "FF15 plz huge jg diff 4 monkeys in my team";
	std::cout << CLR << std::endl;
}
