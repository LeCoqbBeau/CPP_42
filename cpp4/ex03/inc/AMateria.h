//
// Created by mscheman on 8/23/24.
//

#ifndef EX03_AMATERIA_H
#define EX03_AMATERIA_H

#include "ex03_includes.h"
#include "ICharacter.h"

class ICharacter;

class AMateria {
	protected:
		std::string _type;

	public:
		AMateria(const std::string& type);
		virtual ~AMateria();

		const std::string &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};


#endif //EX03_AMATERIA_H
