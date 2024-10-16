#include "RobotomyRequestForm.h"

// Canonical Orthodox Form
RobotomyRequestForm::RobotomyRequestForm() : AForm(ROBOTOMY_NAME, ROBOTOMY_SIGN, ROBOTOMY_EXEC) {
	std::cout << BGRN "RobotomyRequestForm Default Constructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(ROBOTOMY_NAME, ROBOTOMY_SIGN, ROBOTOMY_EXEC) {
	std::cout << BGRN "RobotomyRequestForm Parameterized Constructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src) {
	std::cout << BGRN "RobotomyRequestForm Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << &src << "to" << this << " ] " CLR << std::endl;
	this->_target = src._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	std::cout << BGRN "RobotomyRequestForm Assignment Operator called" CLR;
	std::cout << BBLK " [ from " << &rhs << "to" << this << " ] " CLR << std::endl;
	this->_target = rhs._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << BGRN "RobotomyRequestForm Destructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
}

// Accessors
const std::string& RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::setTarget(const std::string &target) {
	this->_target = target;
}

// Methods
void RobotomyRequestForm::_formAction() const {
	static int	counter = 0;

	std::cout << BYLW "*insert very realistic drilling noises*" CLR << std::endl;
	counter++;
	std::cout << BCYN << _target << CYN " has been ";
	if (counter % 2)
		std::cout << BRED "unsuccessfully";
	else
		std::cout << BGRN "successfully";
	std::cout << CYN " robotomized." CLR << std::endl;
}
