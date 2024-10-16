#include "Bureaucrat.h"

// Canonical Orthodox Form
Bureaucrat::Bureaucrat() : _name("Default") {
	std::cout << BGRN "Bureaucrat Default Constructor called" CLR;
	std::cout << BBLK " [ " << this->_name << " ] " CLR << std::endl;
	this->_grade = 75;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name) {
	std::cout << BGRN "Bureaucrat Parameterized Constructor called" CLR;
	std::cout << BBLK " [ " << this->_name << " ] " CLR << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name) {
	std::cout << BGRN "Bureaucrat Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << this->_name << " ] " CLR << std::endl;
	this->_grade = src._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	std::cout << BGRN "Bureaucrat Assignment Operator called" CLR;
	std::cout << BBLK " [ from " << rhs._name << " to " << this->_name << " ] " CLR << std::endl;
	const_cast<std::string &>(this->_name) = rhs._name;
	this->_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << BGRN "Bureaucrat Destructor called" CLR;
	std::cout << BBLK " [ " << this->_name << " ] " CLR << std::endl;
}

// Accessors
const std::string& Bureaucrat::getName() const {
	return this->_name;
}

const int& Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::changeGrade(const int &grade) {
	if (grade > 0)
		return _upGrade(grade);
	return _downGrade(grade);
}

void Bureaucrat::_upGrade(const int &amount) {
	if (_grade - amount < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade -= amount;
}

void Bureaucrat::_downGrade(const int &amount) {
	if (_grade - amount > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade -= amount;
}

// Stream Output overload
std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat) {
	os << BCYN << bureaucrat.getName() << CYN ", got " BCYN << bureaucrat.getGrade() << CYN " out of 150."CLR;
	return os;
}

// Methods
void Bureaucrat::signForm(AForm &form) {
	if (form.getIsSigned())
	{
		std::cout << PRP "Bureaucrat " BPRP << this->_name << PRP "  couldn't sign form \"";
		std::cout << BPRP << form.getName() << PRP"\" because ";
		std::cout << "it is already signed." << std::endl;
		return ;
	}
	if (this->_grade > form.getSignGrade())
	{
		std::cout << PRP "Bureaucrat " BPRP << this->_name << PRP "  couldn't sign form \"";
		std::cout << BPRP << form.getName() << PRP"\" because ";
		std::cout << "he doesn't understand it." << std::endl;
		return ;
	}
	form.beSigned(*this);
	std::cout << CYN "Bureaucrat " BCYN << this->_name << CYN " signed form \"";
	std::cout << BCYN << form.getName() << CYN"\"." << std::endl;
}

void Bureaucrat::executeForm(const AForm &form) const {
	if (!form.getIsSigned())
	{
		std::cout << PRP "Bureaucrat " BPRP << this->_name << PRP " cant follow the procedure for form \"";
		std::cout << BPRP << form.getName() << PRP"\" because ";
		std::cout << "it is not signed." << std::endl;
		return ;
	}
	if (this->_grade > form.getExecGrade())
	{
		std::cout << PRP "Bureaucrat " BPRP << this->_name << PRP " couldn't execute form \"";
		std::cout << BPRP << form.getName() << PRP"\" because ";
		std::cout << "he doesn't understand what he should do." << std::endl;
		return ;
	}
	std::cout << CYN "Bureaucrat " BCYN << this->_name << CYN " executed form \"";
	std::cout << BCYN << form.getName() << CYN"\"." << std::endl;
	form.execute(*this);
}

// Exceptions
Bureaucrat::GradeTooHighException::GradeTooHighException() throw() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(const Bureaucrat::GradeTooHighException &) throw() {}

Bureaucrat::GradeTooHighException&
Bureaucrat::GradeTooHighException::operator=(const Bureaucrat::GradeTooHighException &) throw() {
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return BRED"Bucreaucrat got promoted due to outstanding performance."CLR;
}

Bureaucrat::GradeTooLowException::GradeTooLowException() throw() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const Bureaucrat::GradeTooLowException &) throw() {}

Bureaucrat::GradeTooLowException &
Bureaucrat::GradeTooLowException::operator=(const Bureaucrat::GradeTooLowException &) throw() {
	return *this;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return BRED"Bucreaucrat got fired due to poor performance."CLR;
}
