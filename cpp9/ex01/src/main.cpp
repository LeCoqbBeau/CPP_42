//
// Created by mscheman on 8/16/24.
//

#include "RPN.h"

int	main(int argc, char *argv[]) {
	(void)argc;

	RPN calculator;
	TRY_RETURN(
		PRINT CYN BOLD "Now calculating: " CENDL;
		calculator.loadCalculation(argv[1]);
	)
}
