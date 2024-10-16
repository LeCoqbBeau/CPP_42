#include "Intern.h"

// Canonical Orthodox Form
const std::string
Intern::formNames[NONE] =
		{SHRUBBERY_NAME,
		 PARDON_NAME,
		 ROBOTOMY_NAME};

Intern::Intern() {
	std::cout << BGRN "Intern Default Constructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
}

Intern::Intern(const Intern &src) {
	std::cout << BGRN "Intern Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << &src << "to" << this << " ] " CLR << std::endl;
}

Intern &Intern::operator=(const Intern &rhs) {
	std::cout << BGRN "Intern Assignment Operator called" CLR;
	std::cout << BBLK " [ from " << &rhs << "to" << this << " ] " CLR << std::endl;
	return *this;
}

Intern::~Intern() {
	std::cout << BGRN "Intern Destructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
}

// Methods
AForm *Intern::makeForm(const std::string &name, const std::string &target) {
	AForm	*form;
	t_form	type = _identifyForm(name);

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
			throw Intern::UnknownForm();
	}
	_printCreation(type);
	return form;
}

t_form Intern::_identifyForm(const std::string &name) {
	for (int i = 0; i < NONE; ++i) {
		if (name == formNames[i])
			return (static_cast<t_form>(i));
	}
	return (NONE);
}

void Intern::_printCreation(t_form form) {
	std::cout << CYN "Intern creates " BCYN;
	switch (form) {
		case SHRUBBERY:
			std::cout << "Shrubbery Creation Form" CYN ".";
			break;
		case PARDON:
			std::cout << "Presidential Pardon Form" CYN ".";
			break;
		case ROBOTOMY:
			std::cout << "Robotomy Request Form" CYN ".";
			break;
		case NONE:
			std::cout << "god wanted to be here form" CYN ".";
			break;
	}
	std::cout << CLR << std::endl;
}

// Exceptions
Intern::UnknownForm::UnknownForm() throw() {}

Intern::UnknownForm::UnknownForm(const Intern::UnknownForm &) throw() {}

Intern::UnknownForm &Intern::UnknownForm::operator=(const Intern::UnknownForm &) throw() {
	return *this;
}

Intern::UnknownForm::~UnknownForm() throw() {}

const char *Intern::UnknownForm::what() const throw() {
	return BRED"Intern couldn't make the form, what a useful intern..."CLR;
}
