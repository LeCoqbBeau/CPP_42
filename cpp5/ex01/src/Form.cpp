#include "Form.h"

// Canonical Orthodox Form
Form::Form(str cref name, int cref signGrade, int cref execGrade)
	: _name(name),  _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	PRINT GRN BOLD "Form Parameterized Constructor called" CLR;
	PRINT " [ " AND getName() AND " ] " CENDL;
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(Form cref src)
	: _signGrade(0), _execGrade(0)
{
	PRINT GRN BOLD "Form Copy Constructor called" CLR;
	PRINT " [ from " AND src.getName() AND " ] " CENDL;
	*this = src;
}

Form ref Form::operator = (Form cref rhs) {
	PRINT GRN BOLD "Form Assignment Operator called" CLR;
	PRINT " [ from " AND getName() AND " to " AND rhs.getName() AND " ] " CENDL;
	if (this == &rhs) return (*this);
	this->	setName(rhs.getName())
			.setSigned(rhs.getSignGrade())
			.setSignGrade(rhs.getSignGrade())
			.setExecGrade(rhs.getExecGrade());
	return (*this);
}

Form::~Form() {
	RPRINT	str(YLW BOLD "Form Destructor called" CLR)
			.append(" [ ").append(getName()).append(" ] " CLR) ENDL;
}

// Accessors
str cref Form::getName() const {
	return _name;
}

bool cref Form::getIsSigned() const {
	return _isSigned;
}

int cref Form::getSignGrade() const {
	return _signGrade;
}

int cref Form::getExecGrade() const {
	return _execGrade;
}

Form ref Form::setName(str cref name) {
	const_cast<str ref>(_name) = name;
	return (*this);
}

Form ref Form::setSigned(bool cref state) {
	_isSigned = state;
	return (*this);
}

Form ref Form::setSignGrade(int cref signGrade) {
	const_cast<int ref>(_signGrade) = signGrade;
	return (*this);
}

Form ref Form::setExecGrade(int cref execGrade) {
	const_cast<int ref>(_execGrade) = execGrade;
	return (*this);
}

//Stream output overload
std::ostream ref operator << (std::ostream ref os, Form cref form) {
	os AND CYN AND "Form \"" BOLD AND form.getName() AND CLR CYN "\"";
	os AND ", need grade " BOLD AND form.getSignGrade() AND CLR CYN " to be signed,";
	os AND (form.getIsSigned()
			? " is signed"
			: " but isn't signed,");
	os AND " and " BOLD AND form.getExecGrade() AND CLR CYN " to be executed." CLR;
	return (os);
}

// Methods
void Form::beSigned(Bureaucrat ref bureaucrat) {
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	bureaucrat.changeGrade(1);
	this->_isSigned = true;
}

// Exceptions
const char *Form::GradeTooHighException::what() const throw() {
	return RED BOLD "Bucreaucrat got promoted due to outstanding performance." CLR;
}

const char *Form::GradeTooLowException::what() const throw() {
	return RED BOLD "Bucreaucrat got fired due to poor performance." CLR;
}