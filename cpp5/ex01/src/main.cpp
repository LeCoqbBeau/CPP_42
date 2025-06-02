//
// Created by mscheman on 8/16/24.
//

#include "Form.h"

int	main()
{
	Form Weak("Weak", 149, 149);
	Form Mid("Mid", 75, 75);
	Form Strong("Strong", 30, 30);
	Form Best("Best", 1, 1);

	Bureaucrat Noob("Noob", 150);
	Bureaucrat Good("Good", 60);
	Bureaucrat Pro("Pro", 20);
	Bureaucrat Hacker("Hacker", 1);

	NEWL;
	Noob.signForm(Weak);
	Good.signForm(Weak);
	Good.signForm(Weak);
	Good.signForm(Strong);
	Pro.signForm(Strong);
	Pro.signForm(Best);
	try {
		Hacker.signForm(Best);
	} catch (std::exception ref e) {
		ERROR e.what() ENDL;
	}
	NEWL;

	Bureaucrat Sneaky("Sneaky", 149);
	Sneaky = Noob;

	NEWL;
	try {
		Best.beSigned(Sneaky);
	} catch (std::exception ref e) {
		ERROR e.what() ENDL;
	}
	NEWL;
}
