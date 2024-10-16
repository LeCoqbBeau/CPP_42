#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <string>
# include "colors.h"

class Form;

# include "Bureaucrat.h"

class Form
{
public:
	// Orthodox Canonical Form
	Form();
	Form(const std::string &name, const int &signGrade, const int &execGrade);
	Form(const Form &src);
	Form&operator=(const Form &rhs);
	~Form();

	// Accessors
	const std::string &getName() const;
	const bool &getIsSigned() const;
	const int &getSignGrade() const;
	const int &getExecGrade() const;

	// Methods
	void beSigned(Bureaucrat &bureaucrat);

	// Exceptions
	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException() throw();
		GradeTooLowException (const GradeTooLowException&) throw();
		GradeTooLowException& operator= (const GradeTooLowException&) throw();
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException() throw();
		GradeTooHighException (const GradeTooHighException&) throw();
		GradeTooHighException& operator= (const GradeTooHighException&) throw();
		virtual const char *what() const throw();
	};

private:
	const std::string _name;
	bool _isSigned;
	const int _signGrade;
	const int _execGrade;
};
std::ostream& operator<<(std::ostream& os, Form& form);


#endif //FORM
