#ifndef FORM_H
# define FORM_H

# include "utils.h"

class AForm;

# include "Bureaucrat.h"

class AForm {
	public:
		// Orthodox Canonical Form
		AForm(str cref name = "Default", int cref signGrade = 75, int cref execGrade = 75);
		AForm(AForm cref src);
		AForm ref operator = (AForm cref rhs);
		virtual ~AForm();

		// Methods
		void beSigned(Bureaucrat ref bureaucrat);
		void execute(Bureaucrat cref executor) const;

		// Accessors
		str cref getName() const;
		bool cref getIsSigned() const;
		int cref getSignGrade() const;
		int cref getExecGrade() const;
		AForm ref setName(str cref name);
		AForm ref setSigned(bool cref state);
		AForm ref setSignGrade(int cref signGrade);
		AForm ref setExecGrade(int cref execGrade);

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				GradeTooHighException() throw();
				GradeTooHighException (GradeTooHighException cref) throw();
				GradeTooHighException ref operator= (GradeTooHighException cref) throw();
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException() throw();
				GradeTooLowException (GradeTooLowException cref) throw();
				GradeTooLowException ref operator= (GradeTooLowException cref) throw();
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				FormNotSignedException() throw();
				FormNotSignedException (FormNotSignedException cref) throw();
				FormNotSignedException ref operator= (FormNotSignedException cref) throw();
				virtual const char *what() const throw();
		};

	private:
		// Attributes
		const str	_name;
		bool		_isSigned;
		const int	_signGrade;
		const int	_execGrade;

		// Pure virtual method
		virtual void _formAction() const = 0;
};
std::ostream ref operator<<(std::ostream ref os, AForm ref form);


#endif //FORM

