#include "ShrubberyCreationForm.h"

// Canonical Orthodox Form
ShrubberyCreationForm::ShrubberyCreationForm() : AForm(SHRUBBERY_NAME, SHRUBBERY_SIGN, SHRUBBERY_EXEC) {
	PRINT GRN BOLD "ShrubberyCreationForm Default Constructor called" CLR;
	PRINT " [ " AND this AND " ] " CENDL;
}

ShrubberyCreationForm::ShrubberyCreationForm(str cref target) : AForm(SHRUBBERY_NAME, SHRUBBERY_SIGN, SHRUBBERY_EXEC) {
	PRINT GRN BOLD "ShrubberyCreationForm Parameterized Constructor called" CLR;
	PRINT " [ " AND this AND " ] " CENDL;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm cref src) : AForm(src) {
	PRINT GRN BOLD "ShrubberyCreationForm Copy Constructor called" CLR;
	PRINT " [ from " AND &src AND "to" AND this AND " ] " CENDL;
	this->_target = src._target;
}

ShrubberyCreationForm ref ShrubberyCreationForm::operator = (ShrubberyCreationForm cref rhs) {
	PRINT GRN BOLD "ShrubberyCreationForm Assignment Operator called" CLR;
	PRINT " [ from " AND &rhs AND "to" AND this AND " ] " CENDL;
	if (this == &rhs) return (*this);
	this->_target = rhs._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	RPRINT	str(YLW BOLD "ShrubberyCreationForm Destructor called" CLR)
			.append(" [ ").append(TOSTR(this)).append(" ] " CLR) ENDL;
}

// Accessors
str cref ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::setTarget(str cref target) {
	this->_target = target;
}

// Methods
void ShrubberyCreationForm::_formAction() const throw() {
	str filePath;
	std::ofstream fileStream;

	filePath = _target + "_shrubbery";
	fileStream.open(filePath.c_str());
	if (!fileStream.is_open()) {
		ERROR RGB(224, 131, 7) "Failed to open " + filePath CENDL;
		return ;
	}

	std::srand(std::time(__nullptr));
	const int num = 1 + std::rand() % 9;
	for (int i = 0; i < num; ++i) {
		fileStream ENDL;
		fileStream AND "     ccee88oo"				ENDL;
		fileStream AND "  C8O8O8Q8PoOb o8oo"		ENDL;
		fileStream AND " dOB69QO8PdUOpugoO9bD"		ENDL;
		fileStream AND "CgggbU8OU qOp qOdoUOdcb"	ENDL;
		fileStream AND "    6OuU  /p u gcoUodpP"	ENDL;
		fileStream AND "      \\\\\\//  /douUP"		ENDL;
		fileStream AND "        \\\\\\////"			ENDL;
		fileStream AND "         |||/\\"			ENDL;
		fileStream AND "         |||\\/"			ENDL;
		fileStream AND "         |||||"				ENDL;
		fileStream AND "   .....//||||\\...."		ENDL;
	}
	fileStream.close();
}
