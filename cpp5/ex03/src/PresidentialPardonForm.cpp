#include "PresidentialPardonForm.h"

// Canonical Orthodox Form
PresidentialPardonForm::PresidentialPardonForm() : AForm(PARDON_NAME, PARDON_SIGN, PARDON_EXEC) {
	std::cout << BGRN "PresidentialPardonForm Default Constructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(PARDON_NAME, PARDON_SIGN, PARDON_EXEC) {
	std::cout << BGRN "PresidentialPardonForm Parameterized Constructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src) {
	std::cout << BGRN "PresidentialPardonForm Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << &src << "to" << this << " ] " CLR << std::endl;
	this->_target = src._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	std::cout << BGRN "PresidentialPardonForm Assignment Operator called" CLR;
	std::cout << BBLK " [ from " << &rhs << "to" << this << " ] " CLR << std::endl;
	this->_target = rhs._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << BGRN "PresidentialPardonForm Destructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
}

// Accessors
const std::string& PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::setTarget(const std::string &target) {
	this->_target = target;
}

// Methods
void PresidentialPardonForm::_formAction() const {
	std::cout << BCYN << _target << CYN " has been paroned by " CLR BOLD "Zaphod Beeblebrox" CYN "." CLR << std::endl;
}
