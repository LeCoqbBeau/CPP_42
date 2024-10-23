//
// Created by mscheman on 8/16/24.
//

#include "RPN.h"

int	main(int argc, char *argv[]) {
	RPN calculator;

	(void)argc;

	try {
		PRINT BCYN "Now calculating: " BYLW AND argv[1] AND CLR ENDL;
		calculator.loadCalculation(argv[1]);
	} catch (std::exception &e) {
		ERROR BRED AND e.what() AND CLR ENDL;
		return (1);
	}
}
