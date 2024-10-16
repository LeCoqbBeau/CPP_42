#include "Form.h"

// Canonical Orthodox Form
Form::Form()
	: _name("Default"), _signGrade(75), _execGrade(75)
{
	std::cout << BGRN "Form Default Constructor called" CLR;
	std::cout << BBLK " [ " << this->_name << " ] " CLR << std::endl;
	this->_isSigned = false;
}

Form::Form(const std::string &name, const int &signGrade, const int &execGrade)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << BGRN "Form Parameterized Constructor called" CLR;
	std::cout << BBLK " [ " << this->_name << " ] " CLR << std::endl;
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	this->_isSigned = false;
}

Form::Form(const Form &src)
	: _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	std::cout << BGRN "Form Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << src._name << " ] " CLR << std::endl;
	this->_isSigned = src._isSigned;
}

Form &Form::operator=(const Form &rhs) {
	std::cout << BGRN "Form Assignment Operator called" CLR;
	std::cout << BBLK " [ from " << rhs._name << " to " << this->_name << " ] " CLR << std::endl;
	const_cast<std::string &>(this->_name) = rhs._name;
	this->_isSigned = rhs._isSigned;
	const_cast<int &>(this->_signGrade) = rhs._signGrade;
	const_cast<int &>(this->_execGrade) = rhs._execGrade;
	return *this;
}

Form::~Form() {
	std::cout << BGRN "Form Destructor called" CLR;
	std::cout << BBLK " [ " << this->_name << " ] " CLR << std::endl;
}

// Accessors
const std::string& Form::getName() const {
	return this->_name;
}

const bool& Form::getIsSigned() const {
	return this->_isSigned;
}

const int& Form::getSignGrade() const {
	return this->_signGrade;
}

const int& Form::getExecGrade() const {
	return this->_execGrade;
}

//Stream output overload
std::ostream &operator<<(std::ostream &os, Form &form) {
	os << CYN << "Form \"" BCYN << form.getName() << CYN "\"";
	os << ", need grade " BCYN << form.getSignGrade() << CYN " to be signed";
	os << " and " BCYN << form.getExecGrade() << CYN " to be executed." CLR;
	return (os);
}

// Methods
void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	bureaucrat.changeGrade(1);
	this->_isSigned = true;
}

// Exceptions
Form::GradeTooLowException::GradeTooLowException() throw() {}

Form::GradeTooLowException::GradeTooLowException(const Form::GradeTooLowException &) throw() {}

Form::GradeTooLowException&
Form::GradeTooLowException::operator=(const Form::GradeTooLowException &) throw() {
	return *this;
}

const char *Form::GradeTooLowException::what() const throw() {
	return BRED"uhhh apparently, there's a problem with a form... having a too low grade..?"CLR;
}

Form::GradeTooHighException::GradeTooHighException() throw() {}

Form::GradeTooHighException::GradeTooHighException(const Form::GradeTooHighException &) throw() {}

Form::GradeTooHighException&
Form::GradeTooHighException::operator=(const Form::GradeTooHighException &) throw() {
	return *this;
}

const char *Form::GradeTooHighException::what() const throw() {
	return BRED"This form is too complex to be filled."CLR;
}