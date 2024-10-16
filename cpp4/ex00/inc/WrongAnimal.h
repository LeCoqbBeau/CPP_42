#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>
# include <string>
# include "colors.h"

class WrongAnimal
{
protected:
	std::string _type;

public:
	// Orthodox Canonical Form
	WrongAnimal();
	WrongAnimal(const std::string &type);
	WrongAnimal(const WrongAnimal &src);
	WrongAnimal&operator=(const WrongAnimal &rhs);
	~WrongAnimal();

	// Methods
	void makeSound();
};

#endif //WRONGANIMAL
