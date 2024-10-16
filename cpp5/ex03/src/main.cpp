//
// Created by mscheman on 8/16/24.
//

#include "AForm.h"
#include <PresidentialPardonForm.h>
#include <RobotomyRequestForm.h>
#include <ShrubberyCreationForm.h>
#include <Intern.h>

int	main()
{
	AForm *form;
	Bureaucrat goat("Goat", 4);
	Intern bob;
	std::string name;

	for (int i = 0; i < NONE; ++i) {
		std::cout << std::endl;
		name = Intern::formNames[i];
		form = bob.makeForm(name, "bob");
		goat.signForm(*form);
		goat.executeForm(*form);
		delete form;
	}

	std::cout << std::endl;
	try {
		form = bob.makeForm("Salary Raise Form", "bob");
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
