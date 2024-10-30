//
// Created by mscheman on 8/19/24.
//

#include "FileReplace.h"

int main(int argc, char *argv[])
{
	(void)argc;
	try {
		FileReplace file(argv[1], argv[2], argv[3]);
		file.run();
	} catch (std::exception &e) {
		std::cerr << BRED << e.what() << CLR << std::endl;
	}
}
