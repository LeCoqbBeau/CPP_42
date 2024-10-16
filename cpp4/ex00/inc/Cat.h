#ifndef CAT_H
# define CAT_H

# include <iostream>
# include "colors.h"

# include "Animal.h"

class Cat : public Animal
{
public:
	// Orthodox Canonical Form
	Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &rhs);
	~Cat();

	// Methods
	void makeSound();
};

#endif //CAT
