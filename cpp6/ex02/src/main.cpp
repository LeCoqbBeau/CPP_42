//
// Created by lecoqbeau on 10/16/24.
//

#include <ctime>
#include <unistd.h>
#include "Base.h"

int main() {
	Base *base;
	srand(std::time(__nullptr));
	for (int i = 1; i <= 100; ++i) {
		base = generate();
		identify(base);
		identify(*base);
		PRINT "" ENDL;
		delete base;
		usleep(25e4);
	}
}
