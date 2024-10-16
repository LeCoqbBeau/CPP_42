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
		void _debug();
		void _info();
		void _warning();
		void _error();
	public:
		void complain(std::string level);
};

#endif //HARL_H
