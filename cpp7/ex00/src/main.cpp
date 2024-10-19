//
// Created by mscheman on 8/16/24.
//

#include <iostream>

#include "template.h"
#include "colors.h"
#include "printUtils.h"

int main() {
	int a = 2;
	int b = 3;

	::swap( a, b );
	NEWL;
	PRINT BPRP "-----[ Initiating Mining Zone Analysis ]-----" CLR ENDL;
	NEWL;
	PRINT PRP " Now comparing production between drills" CLR ENDL;
	PRINT "  Iron ore production of drill " BGRN "a" CLR " = " BGRN AND a AND CLR "ingot/s" ENDL;
	PRINT "  Gold ore production of drill " BCYN "b" CLR " = " BCYN AND b AND CLR "ingot/s" ENDL;
	PRINT BYLW "  min( " BGRN "a" BYLW ", " BCYN "b" BYLW " )" CLR " = " BCYN AND ::min( a, b ) AND CLR "ingots/s" ENDL;
	PRINT BYLW "  max( " BGRN "a" BYLW ", " BCYN "b" BYLW " )" CLR " = " BGRN AND ::max( a, b ) AND CLR "ingots/s" ENDL;
	NEWL;

	PRINT PRP " Now comparing ore values" CLR ENDL;
	std::string c = "Iron";
	std::string d = "Gold";
	::swap(c, d);
	PRINT "  Value of ore " BGRN "c" CLR ", known as : " BGRN AND c AND CLR ENDL;
	PRINT "  Value of ore " BCYN "d" CLR ", known as : " BCYN AND d AND CLR ENDL;
	PRINT BYLW "  min( " BGRN "c" BYLW ", " BCYN "d" BYLW " )" CLR " = " BGRN AND ::min( c, d ) AND CLR ENDL;
	PRINT BYLW "  max( " BGRN "c" BYLW ", " BCYN "d" BYLW " )" CLR " = " BCYN AND ::max( c, d ) AND CLR ENDL;
	PRINT BPRP ENDL AND "-----[ Terminated Mining Zone Analysis ]-----" CLR ENDL ENDL;
	PRINT CLR;

	return 0;
}
