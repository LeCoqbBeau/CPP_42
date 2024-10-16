#ifndef WRONGCAT_H
# define WRONGCAT_H

# include <iostream>
# include "colors.h"

# include "WrongAnimal.h"

class WrongCat : public WrongAnimal
{
public:
	// Orthodox Canonical Form
	WrongCat();
	WrongCat(const WrongCat &src);
	WrongCat&operator=(const WrongCat &rhs);
	~WrongCat();

	// Methods
	void makeSound();
};

#endif //WRONGCAT
