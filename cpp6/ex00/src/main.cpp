//
// Created by lecoqbeau on 10/16/24.
//

#include <iostream>
#include <ScalarConverter.h>

int main(int argc, char *argv[]) {
	// (void)argc;
	// char *end;
	// float num = std::strtod(argv[1], &end);
	// if (*end != 0 && *end != 'f')
	// 	PRINT "error" ENDL;
	// PRINT num ENDL;
	for (int i = 1; i < argc; ++i)
	{
		PRINT BYLW "input " CLR AND argv[i] AND BYLW ": " CLR ENDL;
		Serialize::convert(argv[i]);
		PRINT "" ENDL;
	}
}