//
// Created by mscheman on 8/23/24.
//

#ifndef EX03_IMATERIASOURCE_H
#define EX03_IMATERIASOURCE_H

#include "ex03_includes.h"
#include "AMateria.h"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria *m) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};


#endif //EX03_IMATERIASOURCE_H
