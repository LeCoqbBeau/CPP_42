//
// Created by mscheman on 10/16/24.
//

#ifndef BASE_H
#define BASE_H

#include "colors.h"
#include <iostream>
#include <cmath>

#define PRINT std::cout <<
#define AND <<
#define ENDL << std::endl

typedef enum e_base {
	baseA = 0,
	baseB,
	baseC,
	E_BASE_END
} t_base;

class Base {
public:
	virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate();
void identify(Base* p);
void identify(Base& p);

#endif //BASE_H
