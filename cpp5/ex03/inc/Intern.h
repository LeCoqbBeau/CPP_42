#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include <string>
# include "AForm.h"
# include "PresidentialPardonForm.h"
# include "RobotomyRequestForm.h"
# include "ShrubberyCreationForm.h"
# include "colors.h"

typedef enum e_form {
	SHRUBBERY = 0,
	PARDON,
	ROBOTOMY,
	NONE
} t_form;

class Intern
{
public:
	// Orthodox Canonical Form
	Intern();
	Intern(const Intern &src);
	Intern&operator=(const Intern &rhs);
	~Intern();

	// Attributes
	static const std::string	formNames[NONE];

	// Methods
	AForm *makeForm(const std::string &name, const std::string &target);

	// Exceptions
	class UnknownForm : public std::exception
	{
	public:
		UnknownForm() throw();
		UnknownForm(const UnknownForm &) throw();
		UnknownForm& operator = (const UnknownForm &) throw();
		~UnknownForm() throw();
		const char *what() const throw();
	};
private:
	static t_form				_identifyForm(const std::string &name);
	static void					_printCreation(t_form form);
};

#endif //INTERN
