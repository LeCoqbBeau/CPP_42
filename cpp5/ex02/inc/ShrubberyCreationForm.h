#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include "utils.h"
# include "AForm.h"

# include <fstream>
# include <cstdlib>
# include <ctime>

# define SHRUBBERY_NAME "Shrubbery Creation"
# define SHRUBBERY_SIGN 145
# define SHRUBBERY_EXEC 137

class ShrubberyCreationForm : public AForm {
	public:
		// Orthodox Canonical Form
		ShrubberyCreationForm();
		ShrubberyCreationForm(str cref target = "Default");
		ShrubberyCreationForm(ShrubberyCreationForm cref src);
		ShrubberyCreationForm ref operator = (ShrubberyCreationForm cref rhs);
		~ShrubberyCreationForm();

		// Accessors
		str cref getTarget() const;
		void setTarget(str cref target);

		// Exceptions
		class FileNotOpened : public std::exception {
			public:
				FileNotOpened() throw();
				FileNotOpened(FileNotOpened cref) throw();
				FileNotOpened& operator = (FileNotOpened cref) throw();
				~FileNotOpened() throw();
				const char *what() const throw();
		};

	private:
		str _target;
		void _formAction() const;
};

#endif //SHRUBBERYCREATIONFORM
