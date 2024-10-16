//
// Created by mscheman on 8/20/24.
//

#include "Harl.h"

Harl::Harl() {
	_funcPTR[0] = &Harl::debug;
	_funcPTR[1] = &Harl::info;
	_funcPTR[2] = &Harl::warning;
	_funcPTR[3] = &Harl::error;
}

static void incorrect_level();

void Harl::complain(const std::string &level) {
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
	if (i != -1)
		(this->*_funcPTR[i])();
	else
		incorrect_level();
}

static void incorrect_level()
{
	std::cout << BPRP;
	std::cout << "How could you guess that I don't take any showers ?";
	std::cout << CLR << std::endl;
}

void Harl::debug() {
	std::cout << BCYN;
	std::cout << "I love playing league of legend!";
	std::cout << CLR << std::endl;
}

void Harl::info() {
	std::cout << BGRN;
	std::cout << "I play top lane and really like to split push, that's why I play Tryndamere.";
	std::cout << CLR << std::endl;
}

void Harl::warning() {
	std::cout << BYLW;
	std::cout << "My jungler still hasn't ganked me once whereas they ganked me twice...";
	std::cout << CLR << std::endl;
}

void Harl::error() {
	std::cout << BRED;
	std::cout << "FF15 plz huge jg diff 4 monkeys in my team";
	std::cout << CLR << std::endl;
}
