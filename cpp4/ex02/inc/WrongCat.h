//
// Created by mscheman on 8/22/24.
//

#ifndef EX00_WRONGCAT_H
#define EX00_WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		~WrongCat();
		void makeSound();
};


#endif //EX00_WRONGCAT_H
