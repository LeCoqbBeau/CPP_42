//
// Created by mscheman on 8/19/24.
//

#include "Harl.h"

int main(int argc, char *argv[]) {
	Harl harl;

	if (argc != 2) {
		std::cout << BRED "Invalid number of parameters" CLR << std::endl;
		return 0;
	}
	harl.complain(argv[1]);
}