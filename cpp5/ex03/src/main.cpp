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
	str name;

	for (int i = 0; i < E_FORM_END; ++i) {
		name = Intern::formNames[i];
		form = bob.makeForm(name, "bob");
		goat.signForm(*form);
		goat.executeForm(*form);
		delete form;
	}

	try {
		form = bob.makeForm("Salary Raise Form", "bob");
	} catch (std::exception ref e) {
		ERROR e.what() ENDL;
	}
}
