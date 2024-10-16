//
// Created by mscheman on 8/22/24.
//

#ifndef EX02_FLAGTRAP_H
#define EX02_FLAGTRAP_H

#include "ClapTrap.h"

#define FLAGTRAP_HP 100
#define FLAGTRAP_EP 100
#define FLAGTRAP_AD 30

class FlagTrap : public ClapTrap {
	public:
		FlagTrap();
		FlagTrap(const std::string &name);
		FlagTrap(const FlagTrap &src);
		FlagTrap &operator = (const FlagTrap &rhs);
		~FlagTrap();
		void highFivesGuys(void);
};


#endif //EX02_FLAGTRAP_H
