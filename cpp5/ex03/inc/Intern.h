#ifndef INTERN_H
# define INTERN_H

# include "utils.h"
# include "AForm.h"

# include "PresidentialPardonForm.h"
# include "RobotomyRequestForm.h"
# include "ShrubberyCreationForm.h"

typedef enum e_form {
	SHRUBBERY = 0,
	PARDON,
	ROBOTOMY,
	E_FORM_END
} t_form;

class Intern {
	public:
		// Orthodox Canonical Form
		Intern();
		Intern(Intern cref src);
		Intern ref operator = (Intern cref rhs);
		~Intern();

		// Attributes
		static const str formNames[E_FORM_END];

		// Methods
		AForm *makeForm(str cref name, str cref target);

	private:
		static t_form	_identifyForm(str cref name);
		static void		_printCreation(t_form form);
};

#endif //INTERN
