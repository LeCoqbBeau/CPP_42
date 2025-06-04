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

#define TRY_CATCH(statement) try { statement; } catch (std::exception ref e) { ERROR e.what() ENDL; }

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
		TRY_CATCH(noob.executeForm(*form);)
		TRY_CATCH(signer.signForm(*form);)
		TRY_CATCH(executor.executeForm(*form);)
		TRY_CATCH(noob.executeForm(*form);)
		TRY_CATCH(pro.executeForm(*form);)
		delete form;
	}
}
