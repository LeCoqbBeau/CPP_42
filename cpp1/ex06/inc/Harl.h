//
// Created by mscheman on 8/20/24.
//

#ifndef HARL_H
#define HARL_H

#include <string>
#include <iostream>
#include "colors.h"

#define HARL_FALLTHROUGH __attribute__ ((fallthrough))

enum e_Level {
	DEBUG = 0,
	INFO,
	WARNING,
	ERROR,
	E_LEVEL_END
};

e_Level& operator++(e_Level& s);

class Harl {
	private:
		void _debug();
		void _info();
		void _warning();
		void _error();
	public:
		void complain(const std::string &level);
};

#endif //HARL_H
