#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include <iostream>
# include <string>
# include "AForm.h"
# include "colors.h"

# define ROBOTOMY_NAME "Robotomy Request"
# define ROBOTOMY_SIGN 145
# define ROBOTOMY_EXEC 137

class RobotomyRequestForm : public AForm
{
public:
	// Orthodox Canonical Form
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm&operator=(const RobotomyRequestForm &rhs);
	~RobotomyRequestForm();

	// Accessors
	const std::string &getTarget() const;
	void setTarget(const std::string &target);

private:
	std::string _target;
	void _formAction() const;
};

#endif //ROBOTOMYREQUESTFORM
