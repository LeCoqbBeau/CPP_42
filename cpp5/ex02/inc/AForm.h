#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <string>
# include "colors.h"

class AForm;

# include "Bureaucrat.h"

class AForm
{
public:
	// Orthodox Canonical Form
	AForm();
	AForm(const std::string &name, const int &signGrade, const int &execGrade);
	AForm(const AForm &src);
	AForm&operator=(const AForm &rhs);
	virtual ~AForm();

	// Accessors
	const std::string &getName() const;
	const bool &getIsSigned() const;
	const int &getSignGrade() const;
	const int &getExecGrade() const;

	// Methods
	void beSigned(Bureaucrat &bureaucrat);
	void execute(Bureaucrat const & executor) const;

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
	class FormNotSignedException : public std::exception
	{
	public:
		FormNotSignedException() throw();
		FormNotSignedException (const FormNotSignedException&) throw();
		FormNotSignedException& operator= (const FormNotSignedException&) throw();
		virtual const char *what() const throw();
	};

private:
	const std::string _name;
	bool _isSigned;
	const int _signGrade;
	const int _execGrade;
	virtual void _formAction() const = 0;
};
std::ostream& operator<<(std::ostream& os, AForm& form);


#endif //FORM
