//
// Created by mscheman on 8/16/24.
//

#include "whatever.h"

int main() {
	// My customized main test
	{
		int a = 2;
		int b = 3;

		::swap( a, b );
		NEWL;
		PRINT PRP BOLD "-----[ Initiating Mining Zone Analysis ]-----" CENDL;
		NEWL;
		PRINT PRP " Now comparing production between drills" CENDL;
		PRINT "  Iron ore production of drill " GRN BOLD "a" CLR " = " GRN BOLD AND a AND CLR "ingot/s" ENDL;
		PRINT "  Gold ore production of drill " CYN BOLD "b" CLR " = " CYN BOLD AND b AND CLR "ingot/s" ENDL;
		PRINT YLW BOLD "  min( " GRN BOLD "a" YLW BOLD ", " CYN BOLD "b" YLW BOLD " )" CLR " = " CYN BOLD AND ::min( a, b ) AND CLR "ingots/s" ENDL;
		PRINT YLW BOLD "  max( " GRN BOLD "a" YLW BOLD ", " CYN BOLD "b" YLW BOLD " )" CLR " = " GRN BOLD AND ::max( a, b ) AND CLR "ingots/s" ENDL;
		NEWL;

		PRINT PRP " Now comparing ore values" CENDL;
		std::string c = "Iron";
		std::string d = "Gold";
		::swap(c, d);
		PRINT "  Value of ore " GRN BOLD "c" CLR ", known as : " GRN BOLD AND c CENDL;
		PRINT "  Value of ore " CYN BOLD "d" CLR ", known as : " CYN BOLD AND d CENDL;
		PRINT YLW BOLD "  min( " GRN BOLD "c" YLW BOLD ", " CYN BOLD "d" YLW BOLD " )" CLR " = " GRN BOLD AND ::min( c, d ) CENDL;
		PRINT YLW BOLD "  max( " GRN BOLD "c" YLW BOLD ", " CYN BOLD "d" YLW BOLD " )" CLR " = " CYN BOLD AND ::max( c, d ) CENDL;
		PRINT PRP BOLD ENDL AND "-----[ Terminated Mining Zone Analysis ]-----" CENDL;
		NEWL;
	}
	// Original main test
	/* {
		int a = 2;
		int b = 3;
		::swap( a, b );
		PRINT "a = " AND a AND ", b = " AND b ENDL;
		PRINT "min( a, b ) = " AND ::min( a, b ) ENDL;
		PRINT "max( a, b ) = " AND ::max( a, b ) ENDL;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		PRINT "c = " AND c AND ", d = " AND d ENDL;
		PRINT "min( c, d ) = " AND ::min( c, d ) ENDL;
		PRINT "max( c, d ) = " AND ::max( c, d ) ENDL;
	} */
}
