//
// Created by lecoqbeau on 10/16/24.
//

#include <iostream>
#include <ScalarConverter.h>

int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; ++i) {
		PRINT GRN BOLD "input " CLR AND argv[i] AND GRN BOLD ": " CENDL;
		ScalarConverter::convert(argv[i]);
		NEWL;
	}
}