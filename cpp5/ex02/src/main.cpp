//
// Created by mscheman on 8/16/24.
//

#include "AForm.h"
#include <PresidentialPardonForm.h>
#include <RobotomyRequestForm.h>
#include <ShrubberyCreationForm.h>

#define SHRUBBERY_FORM 0
#define PARDON_FORM 1
#define ROBOTOMY_FORM 2

int	main()
{
	Bureaucrat signer("signer", 4);
	const Bureaucrat executor("executor", 1);
	const Bureaucrat noob("noob", 150);
	const Bureaucrat pro("pro", 1);
	AForm *form;
	for (int i = 0; i < 3; ++i) {
		switch (i) {
			case SHRUBBERY_FORM:
				form = new ShrubberyCreationForm("shrub");
				break;
			case PARDON_FORM:
				form = new PresidentialPardonForm("Some guy");
				break;
			case ROBOTOMY_FORM:
				form = new RobotomyRequestForm("Bob");
				break;
			default:
				return 0;
		}
		PRINT *form ENDL;
		try {
			noob.executeForm(*form);
		} catch (std::exception ref e) {
			ERROR e.what() ENDL;
		}
		signer.signForm(*form);
		executor.executeForm(*form);
		try {
			noob.executeForm(*form);
		} catch (std::exception ref e) {
			ERROR e.what() ENDL;
		}
		try {
			pro.executeForm(*form);
		} catch (std::exception ref e) {
			ERROR e.what() ENDL;
		}
		delete form;
	}
}
