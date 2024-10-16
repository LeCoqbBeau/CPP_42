//
// Created by mscheman on 8/23/24.
//

#ifndef EX03_CURE_H
#define EX03_CURE_H

#include "AMateria.h"

class Cure : public AMateria {
	public:
		Cure();
		AMateria	*clone() const;
		void		use(ICharacter &target);
};


#endif //EX03_CURE_H
