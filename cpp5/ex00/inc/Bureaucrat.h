#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>
# include "colors.h"


class Bureaucrat
{
public:
	// Orthodox Canonical Form
	Bureaucrat();
	Bureaucrat(const std::string &name, const int &grade);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat&operator=(const Bureaucrat &rhs);
	~Bureaucrat();

	// Accessors
	const std::string &getName() const;
	const int &getGrade() const;
	void changeGrade(const int &amount);

	// Exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException() throw();
		GradeTooHighException (const GradeTooHighException&) throw();
		GradeTooHighException& operator= (const GradeTooHighException&) throw();
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException() throw();
		GradeTooLowException (const GradeTooLowException&) throw();
		GradeTooLowException& operator= (const GradeTooLowException&) throw();
		virtual const char *what() const throw();
	};

private:
	const std::string _name;
	int _grade;

	void _upGrade(const int &amount);
	void _downGrade(const int &amount);
};
std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat);

#endif //BUREAUCRAT
