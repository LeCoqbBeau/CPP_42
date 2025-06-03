#include "Intern.h"

// Canonical Orthodox Form
const str Intern::formNames[E_FORM_END] = {
	SHRUBBERY_NAME,
	PARDON_NAME,
	ROBOTOMY_NAME
};

Intern::Intern() {
	PRINT GRN BOLD "Intern Default Constructor called" CLR;
	PRINT " [ " AND this AND " ] " CENDL;
}

Intern::Intern(Intern cref src) {
	PRINT GRN BOLD "Intern Copy Constructor called" CLR;
	PRINT " [ from " AND this AND " to " AND &src AND " ] " CENDL;
	*this = src;
}

Intern ref Intern::operator = (Intern cref rhs) {
	PRINT GRN BOLD "Intern Assignment Operator called" CLR;
	PRINT " [ from " AND this AND " to " AND &rhs AND " ] " CENDL;
	if (this == &rhs) return (*this);
	return *this;
}

Intern::~Intern() {
	RPRINT YLW BOLD "Intern Destructor called" CLR
			" [ " AND this AND " ] " CENDL;
}

// Public Methods
AForm *Intern::makeForm(str cref name, str cref target) {
	AForm	*form;
	const t_form type = _identifyForm(name);

	switch (type) {
		case SHRUBBERY:
			form = new ShrubberyCreationForm(target);
			break;
		case PARDON:
			form = new PresidentialPardonForm(target);
			break;
		case ROBOTOMY:
			form = new RobotomyRequestForm(target);
			break;
		default:
			form = __nullptr;
			break;
	}
	_printCreation(type);
	return form;
}

// Private Methods
t_form Intern::_identifyForm(str cref name) {
	for (int i = 0; i < E_FORM_END; ++i) {
		if (name == formNames[i])
			return (static_cast<t_form>(i));
	}
	return (E_FORM_END);
}

void Intern::_printCreation(const t_form form) {
	PRINT CYN "Intern creates " BOLD;
	switch (form) {
		case SHRUBBERY:
			PRINT "Shrubbery Creation Form" CLR CYN ".";
			break;
		case PARDON:
			PRINT "Presidential Pardon Form" CLR CYN ".";
			break;
		case ROBOTOMY:
			PRINT "Robotomy Request Form" CLR CYN ".";
			break;
		case E_FORM_END:
			PRINT "god wanted to be here form" CLR CYN ".";
			break;
	}
	PRINT "" CENDL;
}
