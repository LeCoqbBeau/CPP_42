//
// Created by mscheman on 10/17/24.
//

#ifndef TEMPLATE_H
#define TEMPLATE_H

template <typename T>
void inline static swap(T &x, T &y) {
	T tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T inline static max(const T &x, const T &y) {
	return x > y ? x : y;
}

template <typename T>
	T inline static min(const T &x, const T &y) {
	return x < y ? x : y;
}

#endif //TEMPLATE_H
