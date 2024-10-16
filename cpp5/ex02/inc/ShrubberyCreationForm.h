#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include <ctime>
# include "AForm.h"
# include "colors.h"

# define SHRUBBERY_NAME "Shrubbery Creation"
# define SHRUBBERY_SIGN 145
# define SHRUBBERY_EXEC 137

class ShrubberyCreationForm : public AForm
{
public:
	// Orthodox Canonical Form
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm&operator=(const ShrubberyCreationForm &rhs);
	~ShrubberyCreationForm();

	// Accessors
	const std::string &getTarget() const;
	void setTarget(const std::string &target);

	// Exceptions
	class FileNotOpened : public std::exception
	{
	public:
		FileNotOpened() throw();
		FileNotOpened(const FileNotOpened &) throw();
		FileNotOpened& operator = (const FileNotOpened &) throw();
		~FileNotOpened() throw();
		const char *what() const throw();
	};

private:
	std::string _target;
	void _formAction() const;
};

#endif //SHRUBBERYCREATIONFORM
