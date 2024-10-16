//
// Created by mscheman on 8/20/24.
//

#ifndef HARL_H
#define HARL_H

#include <string>
#include <iostream>
#include "colors.h"

class Harl {
	private:
		void (Harl::*_funcPTR[4])(void);
		void debug();
		void info();
		void warning();
		void error();
	public:
		Harl();
		void complain(const std::string &level);
};

#endif //HARL_H
