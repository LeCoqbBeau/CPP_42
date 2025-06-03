//
// Created by mscheman on 10/16/24.
//

#ifndef BASE_H
#define BASE_H

#include "utils.h"

#include <cstdlib>

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

Base *generate();
void identify(Base *p);
void identify(Base ref p);

#include "A.h"
#include "B.h"
#include "C.h"

#endif //BASE_H
