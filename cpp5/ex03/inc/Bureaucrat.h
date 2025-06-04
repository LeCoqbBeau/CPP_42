#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include "utils.h"

class Bureaucrat;

# include "AForm.h"

class Bureaucrat {
	public:
		// Orthodox Canonical Form
		Bureaucrat(str cref name = "Someone", int cref grade = 75);
		Bureaucrat(Bureaucrat cref src);
		Bureaucrat ref operator = (Bureaucrat cref rhs);
		~Bureaucrat();

		// Methods
		void changeGrade(int cref amount);
		void signForm(AForm ref form);
		void executeForm(AForm cref form) const;

		// Accessors
		str cref getName() const;
		int cref getGrade() const;
		Bureaucrat ref setName(str cref name);
		Bureaucrat ref setGrade(int cref grade);

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		//	Attributes
		const str _name;
		int _grade;

		//	Private Methods
		void _upGrade(int cref amount);
		void _downGrade(int cref amount);
};

std::ostream ref operator << (std::ostream ref os, Bureaucrat cref bureaucrat);

#endif //BUREAUCRAT