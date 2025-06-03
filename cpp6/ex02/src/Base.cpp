//
// Created by mscheman on 10/16/24.
//

#include "Base.h"

Base::~Base() {}

Base *generate() {
	static unsigned int callNum = 0;
	Base *newBase;

	PRINT YLW BOLD "Call " CLR AND callNum++ AND YLW BOLD " generated: " CLR;
	switch (std::rand() % 3) {
		case baseA:
			newBase = new A;
			PRINT "A" ENDL;
			break;
		case baseB:
			newBase = new B;
			PRINT "B" ENDL;
			break;
		default:
			newBase = new C;
			PRINT "C" ENDL;
			break;
	}
	return (newBase);
}

void identify(Base* p) {
	PRINT CYN BOLD "Identified pointer as a: " CLR;
	if (dynamic_cast<A *>(p))
		PRINT "base A" CLR;
	else if (dynamic_cast<B *>(p))
		PRINT "base B" CLR;
	else if (dynamic_cast<C *>(p))
		PRINT "base C" CLR;
	else
		PRINT RED BOLD "base bozo" CLR;
	NEWL;
}

void identify(Base ref p) {
	PRINT GRN BOLD "Identified reference as a: " CLR;
	try {
		(void)dynamic_cast<A ref>(p);
		PRINT "base A" CLR ENDL;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<B ref>(p);
		PRINT "base B" CLR ENDL;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<C ref>(p);
		PRINT "base C" CLR ENDL;
		return;
	} catch (...) {}
	PRINT RED BOLD "base bozo" CENDL;
}
