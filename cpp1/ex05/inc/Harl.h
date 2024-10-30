//
// Created by mscheman on 8/20/24.
//

#ifndef HARL_H
#define HARL_H

#include <string>
#include <iostream>
#include "colors.h"

#define HARL_LEVEL 4

class Harl {
	private:
		void (Harl::*_funcPTR[HARL_LEVEL])(void);
		std::string _level[HARL_LEVEL];
		void debug();
		void info();
		void warning();
		void error();
	public:
		Harl();
		void complain(const std::string &level);
};

#endif //HARL_H
