#include "RobotomyRequestForm.h"

// Canonical Orthodox Form
RobotomyRequestForm::RobotomyRequestForm()
	: AForm(ROBOTOMY_NAME, ROBOTOMY_SIGN, ROBOTOMY_EXEC)
{
	PRINT GRN BOLD "RobotomyRequestForm Default Constructor called" CLR;
	PRINT " [ " AND this AND " ] " CENDL;
}

RobotomyRequestForm::RobotomyRequestForm(str cref target)
	: AForm(ROBOTOMY_NAME, ROBOTOMY_SIGN, ROBOTOMY_EXEC)
{
	PRINT GRN BOLD "RobotomyRequestForm Parameterized Constructor called" CLR;
	PRINT " [ " AND this AND " ] " CENDL;
	setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm cref src)
	: AForm(src)
{
	PRINT GRN BOLD "RobotomyRequestForm Copy Constructor called" CLR;
	PRINT " [ from " AND this AND "to" AND &src AND " ] " CENDL;
	*this = src;
}

RobotomyRequestForm ref RobotomyRequestForm::operator = (RobotomyRequestForm cref rhs) {
	PRINT GRN BOLD "RobotomyRequestForm Assignment Operator called" CLR;
	PRINT " [ from " AND this AND "to" AND &rhs AND " ] " CENDL;
	if (this == &rhs) return (*this);
	setTarget(rhs.getTarget());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	RPRINT	str(YLW BOLD "RobotomyRequestForm Destructor called" CLR)
			.append(" [ ").append(TOSTR(this)).append(" ] " CLR) ENDL;
}

// Accessors
str cref RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::setTarget(str cref target) {
	this->_target = target;
}

// Methods
void RobotomyRequestForm::_formAction() const throw() {
	static int	counter = 0;

	PRINT YLW BOLD "*insert very realistic drilling noises*" CENDL;
	counter++;
	PRINT CYN BOLD AND getTarget() AND CYN " has been ";
	if (counter % 2)
		PRINT RED BOLD "unsuccessfully" CLR;
	else
		PRINT GRN BOLD "successfully" CLR;
	PRINT CYN " robotomized." CENDL;
}
