//
// Created by mscheman on 8/20/24.
//

#include "Harl.h"

static void incorrect_level();

e_Level& operator++(e_Level& s) {
	s = static_cast<e_Level>(s + 1);
	return s;
}

static e_Level strToLevel(const std::string &level) {
	const std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};

	for (e_Level i = DEBUG; i < E_LEVEL_END; ++i) {
		if (level == levels[i])
			return (i);
	}
	return (E_LEVEL_END);
}

void Harl::complain(const std::string &level) {
	e_Level log = strToLevel(level);

	switch (log) {
		case DEBUG:
			_debug();
			HARL_FALLTHROUGH;
		case INFO:
			_info();
			HARL_FALLTHROUGH;
		case WARNING:
			_warning();
			HARL_FALLTHROUGH;
		case ERROR:
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
