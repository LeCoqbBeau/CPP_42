#ifndef FORM_H
# define FORM_H

# include "utils.h"

class Form;

# include "Bureaucrat.h"

class Form {
	public:
		// Orthodox Canonical Form
		Form(str cref name = "Default", int cref signGrade = 75, int cref execGrade = 75);
		Form(Form cref src);
		Form ref operator = (Form cref rhs);
		~Form();

		// Methods
		void beSigned(Bureaucrat ref bureaucrat);

		// Accessors
		str cref getName() const;
		bool cref getIsSigned() const;
		int cref getSignGrade() const;
		int cref getExecGrade() const;
		Form ref setName(str cref name);
		Form ref setSigned(bool cref state);
		Form ref setSignGrade(int cref signGrade);
		Form ref setExecGrade(int cref execGrade);

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		// Attributes
		const str	_name;
		bool		_isSigned;
		const int	_signGrade;
		const int	_execGrade;
};
std::ostream ref operator << (std::ostream ref os, Form cref form);

#endif //FORM
