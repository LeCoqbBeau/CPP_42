#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include "utils.h"
# include "AForm.h"

# define PARDON_NAME "Presidential Pardon"
# define PARDON_SIGN 145
# define PARDON_EXEC 137

class PresidentialPardonForm : public AForm {
	public:
		// Orthodox Canonical Form
		PresidentialPardonForm(str cref target = "Default");
		PresidentialPardonForm(PresidentialPardonForm cref src);
		PresidentialPardonForm ref operator = (PresidentialPardonForm cref rhs);
		~PresidentialPardonForm();

		// Accessors
		str cref getTarget() const;
		void setTarget(str cref target);

	private:
		str _target;
		void _formAction() const throw();
};

#endif //PRESIDENTIALPARDONFORM
