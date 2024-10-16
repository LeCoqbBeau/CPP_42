//
// Created by mscheman on 8/16/24.
//

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int	main()
{
	std::cout << std::endl;
	{
		Animal empty;
		Cat cat;
		Dog dog;

		std::cout << std::endl;
		empty.makeSound();
		cat.makeSound();
		dog.makeSound();
		std::cout << std::endl;
	};
	std::cout << std::endl;
	{
		Animal *empty = new Animal();
		Animal *dog = new Dog();
		Animal *cat = new Cat();

		std::cout << std::endl;
		cat->makeSound();
		dog->makeSound();
		empty->makeSound();
		std::cout << std::endl;

		delete empty;
		delete dog;
		delete cat;
	};
	std::cout << std::endl;
	{
		WrongAnimal	wrongEmpty;
		WrongCat	wrongCat;

		std::cout << std::endl;
		wrongEmpty.makeSound();
		wrongCat.makeSound();
		std::cout << std::endl;
	};
	std::cout << std::endl;
	{
		WrongAnimal	*wrongEmpty = new WrongAnimal;
		WrongAnimal	*wrongCat = new WrongCat;

		std::cout << std::endl;
		wrongEmpty->makeSound();
		wrongCat->makeSound();
		std::cout << std::endl;

		delete wrongEmpty;
		delete wrongCat;
	};
	std::cout << std::endl;
	return 0;
}
