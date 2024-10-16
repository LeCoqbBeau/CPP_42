#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include <iostream>
# include <string>
# include "colors.h"
# include "AForm.h"

# define PARDON_NAME "Presidential Pardon"
# define PARDON_SIGN 145
# define PARDON_EXEC 137

class PresidentialPardonForm : public AForm
{
public:
	// Orthodox Canonical Form
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm&operator=(const PresidentialPardonForm &rhs);
	~PresidentialPardonForm();

	// Accessors
	const std::string &getTarget() const;
	void setTarget(const std::string &target);

private:
	std::string _target;
	void _formAction() const;
};

#endif //PRESIDENTIALPARDONFORM
