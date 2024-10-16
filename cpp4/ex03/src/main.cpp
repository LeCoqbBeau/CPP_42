//
// Created by mscheman on 8/16/24.
//

#include "AMateria.h"
#include "Character.h"
#include "MateriaList.h"
#include "MateriaSource.h"
#include "Ice.h"
#include "Cure.h"

int	main()
{
	ICharacter		*him = new Character;
	AMateria		*ice = new Ice();
	AMateria		*cure = new Cure();
	IMateriaSource	*source = new MateriaSource();
	AMateria		*tmp;

	source->learnMateria(ice);
	source->learnMateria(cure);

	tmp = source->createMateria("ice");
	him->equip(tmp);
	tmp = source->createMateria("cure");
	him->equip(tmp);

	Character bob("bob");

	him->use(0, bob);
	him->use(1, bob);
	him->use(2, bob);
	him->use(3, bob);
	delete source;
	delete him;
}
