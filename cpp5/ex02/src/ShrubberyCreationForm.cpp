#include "ShrubberyCreationForm.h"

// Canonical Orthodox Form
ShrubberyCreationForm::ShrubberyCreationForm() : AForm(SHRUBBERY_NAME, SHRUBBERY_SIGN, SHRUBBERY_EXEC) {
	std::cout << BGRN "ShrubberyCreationForm Default Constructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(SHRUBBERY_NAME, SHRUBBERY_SIGN, SHRUBBERY_EXEC) {
	std::cout << BGRN "ShrubberyCreationForm Parameterized Constructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src) {
	std::cout << BGRN "ShrubberyCreationForm Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << &src << "to" << this << " ] " CLR << std::endl;
	this->_target = src._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	std::cout << BGRN "ShrubberyCreationForm Assignment Operator called" CLR;
	std::cout << BBLK " [ from " << &rhs << "to" << this << " ] " CLR << std::endl;
	this->_target = rhs._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << BGRN "ShrubberyCreationForm Destructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
}

// Accessors
const std::string& ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::setTarget(const std::string &target) {
	this->_target = target;
}

// Methods
void ShrubberyCreationForm::_formAction() const {
	std::string filePath;
	std::ofstream fileStream;

	filePath = _target + "_shrubbery";
	fileStream.open(filePath.c_str());
	if (!fileStream.is_open())
		throw ShrubberyCreationForm::FileNotOpened();
	int	num;

	srand(std::time(__nullptr));
	num = 1 + rand() % 9;
	for (int i = 0; i < num; ++i) {
		fileStream << std::endl;
		fileStream << "     ccee88oo"			<< std::endl;
		fileStream << "  C8O8O8Q8PoOb o8oo"		<< std::endl;
		fileStream << " dOB69QO8PdUOpugoO9bD"	<< std::endl;
		fileStream << "CgggbU8OU qOp qOdoUOdcb"	<< std::endl;
		fileStream << "    6OuU  /p u gcoUodpP"	<< std::endl;
		fileStream << "      \\\\\\//  /douUP"	<< std::endl;
		fileStream << "        \\\\\\////"		<< std::endl;
		fileStream << "         |||/\\"			<< std::endl;
		fileStream << "         |||\\/"			<< std::endl;
		fileStream << "         |||||"			<< std::endl;
		fileStream << "   .....//||||\\...."	<< std::endl;
	}
	fileStream.close();
}

// Exceptions
ShrubberyCreationForm::FileNotOpened::FileNotOpened() throw() {}

ShrubberyCreationForm::FileNotOpened::FileNotOpened(const ShrubberyCreationForm::FileNotOpened &) throw() {}

ShrubberyCreationForm::FileNotOpened &
ShrubberyCreationForm::FileNotOpened::operator=(const ShrubberyCreationForm::FileNotOpened &) throw() {
	return *this;
}

ShrubberyCreationForm::FileNotOpened::~FileNotOpened() throw() {}

const char *ShrubberyCreationForm::FileNotOpened::what() const throw() {
	return BRED"Shrubbery Creation Form does not have a valid permission form"CLR;
}
