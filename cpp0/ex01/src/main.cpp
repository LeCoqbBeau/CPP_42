//
// Created by mscheman on 8/16/24.
//

#include "PhoneBook.h"

int	main()
{
	PhoneBook phone;
	std::string input;

	input = "";
	std::cout << CLR_TERM << std::endl;
	std::cout << CYN " Welcome to : " BCYN "My Awesome PhoneBook" CLR << std::endl;
	while (true)
	{
		std::cout << " > ";
		std::getline(std::cin, input);
		if (input == "EXIT" || std::cin.eof())
			break ;
		else if (input == "ADD")
			phone.add();
		else if (input == "SEARCH")
			phone.search();
		else
			std::cout << BRED " Unrecognized command..." CLR << std::endl;
		input = "";
	}
	phone.exit();
}
