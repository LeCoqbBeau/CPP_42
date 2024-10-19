//
// Created by mscheman on 10/17/24.
//

#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>
typedef unsigned int uint;

template<class T>
class Array {
public:
	// Cannonical Orthodox Form
	Array() : _size(0) {
		_array = new T [_size];
	}

	Array(uint n) : _size(n) {
		_array = new T [_size];
	}

	Array(const Array &src) {
		this = src;
	}

	Array &operator = (const Array &rhs) {
		if (this == rhs)
			return *this;
		const_cast<uint>(this->_size) = rhs.size();
		_array = new T [_size];
		for (uint i = 0; i < _size; ++i) {
			_array[i] = rhs._array[i];
		}
		return *this;
	}

	~Array() {
		try {
			delete[] _array;
		} catch (...) {};
	}

	// Overloads
	T &operator [] (const uint idx) {
		if (idx >= _size)
			throw std::out_of_range("");
		return _array[idx];
	}

	// Methods
	const uint &size() {
		return _size;
	}

	const T *data() {
		return _array;
	}

private:
	const uint _size;
	T	*_array;
};


#endif //ARRAY_H
