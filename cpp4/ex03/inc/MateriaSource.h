//
// Created by mscheman on 8/26/24.
//

#ifndef EX03_MATERIASOURCE_H
#define EX03_MATERIASOURCE_H

#include "ex03_includes.h"
#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource {
	private:
		AMateria	*_inventory[INV_SIZE];
		int			_last_index;
	public:
		MateriaSource();
		~MateriaSource();
		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);
};


#endif //EX03_MATERIASOURCE_H
