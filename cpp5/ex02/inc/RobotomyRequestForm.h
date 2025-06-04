#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "utils.h"
# include "AForm.h"

# define ROBOTOMY_NAME "Robotomy Request"
# define ROBOTOMY_SIGN 145
# define ROBOTOMY_EXEC 137

class RobotomyRequestForm : public AForm {
	public:
		// Orthodox Canonical Form
		RobotomyRequestForm();
		RobotomyRequestForm(str cref target = "Default");
		RobotomyRequestForm(RobotomyRequestForm cref src);
		RobotomyRequestForm ref operator=(RobotomyRequestForm cref rhs);
		~RobotomyRequestForm();

		// Accessors
		str cref getTarget() const;
		void setTarget(str cref target);

	private:
		str _target;
		void _formAction() const throw();
};

#endif //ROBOTOMYREQUESTFORM
