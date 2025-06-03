//
// Created by mscheman on 10/17/24.
//

#ifndef ITER_H
# define ITER_H

template<typename T, typename F>
void inline static iter(T array[], const size_t size, F func) {
	for (size_t i = 0; i < size; ++i) {
		func(array[i]);
	}
}

template<typename T, typename F>
void inline static iter(const T array[], const size_t size, F func) {
	for (size_t i = 0; i < size; ++i) {
		func(array[i]);
	}
}

#endif //ITER_H
