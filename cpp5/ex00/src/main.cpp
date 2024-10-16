//
// Created by mscheman on 8/16/24.
//

#include <cstdlib>
#include "Bureaucrat.h"

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << BPRP"Dont forget to put numbers"CLR << std::endl;
		return 0;
	}
	Bureaucrat automated("automated", 75);
	int	change;

	std::string numptr;
	bool		isnum;
	std::cout << automated << std::endl;
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
			std::cout << e.what() << std::endl;
			continue ;
		}
		std::cout << automated << std::endl;
	}
}
