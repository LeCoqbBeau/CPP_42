//
// Created by mscheman on 8/23/24.
//

#ifndef EX03_CHARACTER_H
#define EX03_CHARACTER_H

#include "ICharacter.h"
#include "MateriaList.h"

class Character : public ICharacter {
	private:
		std::string	_name;
		AMateria	*_inventory[INV_SIZE];
		MateriaList	*_materiaList;
	public:
		Character();
		Character(const std::string &name);
		
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};


#endif //EX03_CHARACTER_H
