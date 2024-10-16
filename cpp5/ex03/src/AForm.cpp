#include "AForm.h"

// Canonical Orthodox AForm
AForm::AForm()
	: _name("Default"), _signGrade(75), _execGrade(75)
{
	std::cout << BGRN "AForm Default Constructor called" CLR;
	std::cout << BBLK " [ " << this->_name << " ] " CLR << std::endl;
	this->_isSigned = false;
}

AForm::AForm(const std::string &name, const int &signGrade, const int &execGrade)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << BGRN "AForm Parameterized Constructor called" CLR;
	std::cout << BBLK " [ " << this->_name << " ] " CLR << std::endl;
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	this->_isSigned = false;
}

AForm::AForm(const AForm &src)
	: _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	std::cout << BGRN "AForm Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << src._name << " ] " CLR << std::endl;
	this->_isSigned = src._isSigned;
}

AForm &AForm::operator=(const AForm &rhs) {
	std::cout << BGRN "AForm Assignment Operator called" CLR;
	std::cout << BBLK " [ from " << rhs._name << " to " << this->_name << " ] " CLR << std::endl;
	const_cast<std::string &>(this->_name) = rhs._name;
	this->_isSigned = rhs._isSigned;
	const_cast<int &>(this->_signGrade) = rhs._signGrade;
	const_cast<int &>(this->_execGrade) = rhs._execGrade;
	return *this;
}

AForm::~AForm() {
	std::cout << BGRN "AForm Destructor called" CLR;
	std::cout << BBLK " [ " << this->_name << " ] " CLR << std::endl;
}

// Accessors
const std::string& AForm::getName() const {
	return this->_name;
}

const bool& AForm::getIsSigned() const {
	return this->_isSigned;
}

const int& AForm::getSignGrade() const {
	return this->_signGrade;
}

const int& AForm::getExecGrade() const {
	return this->_execGrade;
}

//Stream output overload
std::ostream &operator<<(std::ostream &os, AForm &form) {
	os << CYN << "AForm \"" BCYN << form.getName() << CYN "\"";
	os << ", need grade " BCYN << form.getSignGrade() << CYN " to be signed";
	os << " and " BCYN << form.getExecGrade() << CYN " to be executed." CLR;
	return (os);
}

// Methods
void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	bureaucrat.changeGrade(1);
	this->_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_execGrade)
		throw AForm::GradeTooLowException();
	_formAction();
}

// Exceptions
AForm::GradeTooLowException::GradeTooLowException() throw() {}

AForm::GradeTooLowException::GradeTooLowException(const AForm::GradeTooLowException &) throw() {}

AForm::GradeTooLowException&
AForm::GradeTooLowException::operator=(const AForm::GradeTooLowException &) throw() {
	return *this;
}

const char *AForm::GradeTooLowException::what() const throw() {
	return BRED"uhhh apparently, there's a problem with a form... having a too low grade..?"CLR;
}

AForm::GradeTooHighException::GradeTooHighException() throw() {}

AForm::GradeTooHighException::GradeTooHighException(const AForm::GradeTooHighException &) throw() {}

AForm::GradeTooHighException&
AForm::GradeTooHighException::operator=(const AForm::GradeTooHighException &) throw() {
	return *this;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return BRED"This form is too complex to be filled."CLR;
}

AForm::FormNotSignedException::FormNotSignedException() throw() {}

AForm::FormNotSignedException::FormNotSignedException(const AForm::FormNotSignedException &) throw() {}

AForm::FormNotSignedException &AForm::FormNotSignedException::operator=(const AForm::FormNotSignedException &) throw() {
	return *this;
}

const char *AForm::FormNotSignedException::what() const throw() {
	return BRED"This form is not signed, i'm sorry it's classic procedures."CLR;
}
