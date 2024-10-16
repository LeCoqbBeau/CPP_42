//
// Created by mscheman on 8/19/24.
//

#include "FileReplace.h"

int main(int argc, char *argv[])
{
	if (argc != 4)
		return error(0);
	FileReplace file(argv[1], argv[2], argv[3]);
	file.run();
}

int	error(int num)
{
	std::cout << BRED;
	if (num == 0)
		std::cout << "Invalid numbers of parameters";
	else if (num == 1)
		std::cout << "Couldn't open the infile";
	else if (num == 2)
		std::cout << "Couldn't open the outfile";
	std::cout << CLR << std::endl;
	return (EXIT_FAILURE);
}
