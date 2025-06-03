#include "Bureaucrat.h"

// Canonical Orthodox Form
Bureaucrat::Bureaucrat(str cref name, int cref grade)
	: _name(name), _grade(grade)
{
	PRINT GRN BOLD "Bureaucrat Parameterized Constructor called" CLR;
	PRINT " [ " AND getName() AND " ] " CENDL;
	if (getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	if (getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat cref src) {
	PRINT GRN BOLD "Bureaucrat Copy Constructor called" CLR;
	PRINT " [ from " AND src.getName() AND " ] " CENDL;
	*this = src;
}

Bureaucrat ref Bureaucrat::operator = (Bureaucrat cref rhs) {
	PRINT GRN BOLD "Bureaucrat Assignment Operator called" CLR;
	PRINT " [ from " AND getName() AND "to" AND rhs.getName() AND " ] " CENDL;
	if (this == &rhs) return (*this);
	this->setName(rhs.getName()).setGrade(rhs.getGrade());
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	RPRINT	str(YLW BOLD "Bureaucrat Destructor called" CLR)
			.append(" [ ").append(getName()).append(" ] " CLR) ENDL;
}

// Public Methods
void Bureaucrat::changeGrade(int cref amount) {
	if (amount > 0)
		return _upGrade(amount);
	return _downGrade(amount);
}

// Methods
void Bureaucrat::signForm(Form ref form) {
	if (form.getIsSigned())
	{
		PRINT PRP "Bureaucrat " PRP BOLD AND this->_name AND PRP " couldn't sign form \"";
		PRINT PRP BOLD AND form.getName() AND PRP"\" because ";
		PRINT "it is already signed." ENDL;
		return ;
	}
	if (this->_grade > form.getSignGrade())
	{
		PRINT PRP "Bureaucrat " PRP BOLD AND this->_name AND PRP " couldn't sign form \"";
		PRINT PRP BOLD AND form.getName() AND PRP "\" because ";
		PRINT "he doesn't understand it." ENDL;
		return ;
	}
	form.beSigned(*this);
	PRINT CYN "Bureaucrat " CYN BOLD AND this->_name AND CYN " signed form \"";
	PRINT CYN BOLD AND form.getName() AND CYN"\"." ENDL;
}

// Accessors
str cref Bureaucrat::getName() const {
	return _name;
}

int cref Bureaucrat::getGrade() const {
	return _grade;
}

Bureaucrat ref Bureaucrat::setName(str cref name) {
	const_cast<str ref>(this->_name) = name;
	return (*this);
}

Bureaucrat ref Bureaucrat::setGrade(int cref grade) {
	_grade = grade;
	return (*this);
}

// Private Methods
void Bureaucrat::_upGrade(int cref amount) {
	if (_grade - amount < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade -= amount;
}

void Bureaucrat::_downGrade(int cref amount) {
	// amount is negative
	if (_grade - amount > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade -= amount;
}

// Stream Output overload
std::ostream ref operator << (std::ostream ref os, Bureaucrat cref bureaucrat) {
	os	AND CYN BOLD AND bureaucrat.getName()
		AND CLR CYN ", got " CYN BOLD AND bureaucrat.getGrade() AND CLR CYN " out of 150." CLR;
	return os;
}

// Exceptions
Bureaucrat::GradeTooHighException::GradeTooHighException() throw() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(Bureaucrat::GradeTooHighException cref) throw() {}

Bureaucrat::GradeTooHighException ref
Bureaucrat::GradeTooHighException::operator = (Bureaucrat::GradeTooHighException cref) throw() {
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return RED BOLD "Bucreaucrat got promoted due to outstanding performance." CLR;
}

Bureaucrat::GradeTooLowException::GradeTooLowException() throw() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(Bureaucrat::GradeTooLowException cref) throw() {}

Bureaucrat::GradeTooLowException ref
Bureaucrat::GradeTooLowException::operator=(Bureaucrat::GradeTooLowException cref) throw() {
	return (*this);
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return RED BOLD "Bucreaucrat got fired due to poor performance." CLR;
}
