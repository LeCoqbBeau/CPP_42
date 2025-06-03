//
// Created by mscheman on 10/17/24.
//

#ifndef TEMPLATE_H
# define TEMPLATE_H

# include "utils.h"

template <typename T>
void inline static swap(T ref x, T ref y) {
	// T tmp = x;
	// x = y;
	// y = tmp;
	std::swap(x, y);
}

template <typename T>
T inline static max(T cref x, T cref y) {
	// return x > y ? x : y;
	return std::max(x, y);
}

template <typename T>
T inline static min(T cref x, T cref y) {
	// return x > y ? y : x;
	return std::min(x, y);
}

#endif //TEMPLATE_H
