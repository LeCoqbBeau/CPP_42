#include "PresidentialPardonForm.h"

// Canonical Orthodox Form
PresidentialPardonForm::PresidentialPardonForm(str cref target)
	: AForm(PARDON_NAME, PARDON_SIGN, PARDON_EXEC)
{
	PRINT GRN BOLD "PresidentialPardonForm Parameterized Constructor called" CLR;
	PRINT " [ " AND this AND " ] " CENDL;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm cref src)
	: AForm(src)
{
	PRINT GRN BOLD "PresidentialPardonForm Copy Constructor called" CLR;
	PRINT " [ from " AND this AND "to" AND &src AND " ] " CENDL;
	*this = src;
}

PresidentialPardonForm ref PresidentialPardonForm::operator = (PresidentialPardonForm cref rhs) {
	PRINT GRN BOLD "PresidentialPardonForm Assignment Operator called" CLR;
	PRINT " [ from " AND this AND "to" AND &rhs AND " ] " CENDL;
	if (this == &rhs) return (*this);
	setTarget(rhs.getTarget());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	RPRINT	str(YLW BOLD "PresidentialPardonForm Destructor called" CLR)
			.append(" [ ").append(TOSTR(this)).append(" ] " CLR) ENDL;
}

// Accessors
str cref PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::setTarget(str cref target) {
	this->_target = target;
}

// Methods
void PresidentialPardonForm::_formAction() const throw() {
	PRINT CYN BOLD AND _target AND CLR CYN " has been pardoned by " CLR BOLD "Zaphod Beeblebrox" CYN "." CENDL;
}
