//
// Created by lecoqbeau on 10/16/24.
//

#include "Base.h"
#include <ctime>

int main() {
	Base *base;
	std::srand(std::time(__nullptr));
	for (int i = 1; i <= 100; ++i) {
		base = generate();
		identify(base);
		identify(*base);
		NEWL;
		delete base;
		usleep(75e3);
	}
}
