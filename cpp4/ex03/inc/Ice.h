//
// Created by mscheman on 8/23/24.
//

#ifndef EX03_ICE_H
#define EX03_ICE_H

#include "AMateria.h"

class Ice : public AMateria {
	public:
		Ice();
		AMateria	*clone() const;
		void		use(ICharacter &target);
};


#endif //EX03_ICE_H
