//
// Created by mscheman on 8/16/24.
//

#include <cstdlib>
#include "Bureaucrat.h"

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		PRINT PRP BOLD "Dont forget to put numbers" CENDL;
		return 0;
	}
	Bureaucrat automated("automated");

	int		change;
	str		numptr;
	bool	isnum;
	PRINT automated ENDL;
	for (int i = 1; i < argc; ++i) {
		numptr = argv[i];
		isnum = true;
		for (std::string::iterator it = numptr.begin(); it != numptr.end(); ++it) {
			if (!isdigit(*it) && *it != '-' && *it != '+')
				isnum = false;
		}
		if (!isnum)
			continue;
		change = std::atoi(argv[i]);
		try {
			automated.changeGrade(change);
		}
		catch (std::exception &e) {
			ERROR e.what() ENDL;
			ERROR RED AND automated.getName() AND " grade is now: " CLR AND automated.getGrade() ENDL;
			continue ;
		}
		PRINT automated ENDL;
	}
}
