#include "AForm.h"

// Canonical Orthodox Form
AForm::AForm(str cref name, int cref signGrade, int cref execGrade)
	: _name(name),  _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	PRINT GRN BOLD "AForm Parameterized Constructor called" CLR;
	PRINT " [ " AND getName() AND " ] " CENDL;
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(AForm cref src)
	: _signGrade(0), _execGrade(0)
{
	PRINT GRN BOLD "AForm Copy Constructor called" CLR;
	PRINT " [ from " AND src.getName() AND " ] " CENDL;
	*this = src;
}

AForm ref AForm::operator = (AForm cref rhs) {
	PRINT GRN BOLD "AForm Assignment Operator called" CLR;
	PRINT " [ from " AND getName() AND " to " AND rhs.getName() AND " ] " CENDL;
	if (this == &rhs) return (*this);
	this->	setName(rhs.getName())
			.setSigned(rhs.getSignGrade())
			.setSignGrade(rhs.getSignGrade())
			.setExecGrade(rhs.getExecGrade());
	return (*this);
}

AForm::~AForm() {
	RPRINT	str(YLW BOLD "AForm Destructor called" CLR)
			.append(" [ ").append(getName()).append(" ] " CLR) ENDL;
}

// Accessors
str cref AForm::getName() const {
	return _name;
}

bool cref AForm::getIsSigned() const {
	return _isSigned;
}

int cref AForm::getSignGrade() const {
	return _signGrade;
}

int cref AForm::getExecGrade() const {
	return _execGrade;
}

AForm ref AForm::setName(str cref name) {
	const_cast<str ref>(_name) = name;
	return (*this);
}

AForm ref AForm::setSigned(bool cref state) {
	_isSigned = state;
	return (*this);
}

AForm ref AForm::setSignGrade(int cref signGrade) {
	const_cast<int ref>(_signGrade) = signGrade;
	return (*this);
}

AForm ref AForm::setExecGrade(int cref execGrade) {
	const_cast<int ref>(_execGrade) = execGrade;
	return (*this);
}

//Stream output overload
std::ostream ref operator << (std::ostream ref os, AForm cref form) {
	os AND CYN AND "AForm \"" BOLD AND form.getName() AND CLR CYN "\"";
	os AND ", need grade " BOLD AND form.getSignGrade() AND CLR CYN " to be signed,";
	os AND (form.getIsSigned()
			? " is signed"
			: " but isn't signed,");
	os AND " and " BOLD AND form.getExecGrade() AND CLR CYN " to be executed." CLR;
	return (os);
}

// Methods
void AForm::beSigned(Bureaucrat ref bureaucrat) {
	if (bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	bureaucrat.changeGrade(1);
	setSigned(true);
}

void AForm::execute(Bureaucrat cref executor) const {
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	_formAction();
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw() {
	return RED BOLD "Bucreaucrat got promoted due to outstanding performance." CLR;
}

const char *AForm::GradeTooLowException::what() const throw() {
	return RED BOLD "Bucreaucrat got fired due to poor performance." CLR;
}

const char *AForm::FormNotSignedException::what() const throw() {
	return RED BOLD "This form is not signed, i'm sorry it's classic procedures." CLR;
}