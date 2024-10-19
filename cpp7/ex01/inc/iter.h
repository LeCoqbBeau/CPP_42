//
// Created by mscheman on 10/17/24.
//

#ifndef ITER_H
#define ITER_H

template<typename T>
void inline static iter(T array[], size_t size, void (*f)(T)) {
	for (size_t i = 0; i < size; ++i) {
		f(array[i]);
	}
}

template<typename T>
void inline static iter(T array[], size_t size, void (*f)(T&)) {
	for (size_t i = 0; i < size; ++i) {
		f(array[i]);
	}
}

template<typename T>
void inline static iter(const T array[], size_t size, void (*f)(const T)) {
	for (size_t i = 0; i < size; ++i) {
		f(array[i]);
	}
}

template<typename T>
void inline static iter(const T array[], size_t size, void (*f)(const T&)) {
	for (size_t i = 0; i < size; ++i) {
		f(array[i]);
	}
}

#endif //ITER_H
