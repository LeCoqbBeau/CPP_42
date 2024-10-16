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
	Bureaucrat executor("executor", 1);
	Bureaucrat noob("noob", 150);
	Bureaucrat pro("pro", 1);
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
				throw ;
		}
		try {
			noob.executeForm(*form);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		signer.signForm(*form);
		executor.executeForm(*form);
		try {
			noob.executeForm(*form);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			pro.executeForm(*form);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		delete form;
		std::cout << std::endl;
	}
}
