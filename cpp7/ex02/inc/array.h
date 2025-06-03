//
// Created by mscheman on 10/17/24.
//

#ifndef ARRAY_H
# define ARRAY_H

# include "utils.h"
# include <stdexcept>

template<class T>
class Array {
	public:
		// Canonical Orthodox Form
		Array(const uint n = 0) : _size(n) {
			_array = new T [_size];
		}

		Array(Array cref src) : _size(0), _array(__nullptr) {
			*this = src;
		}

		Array ref operator = (Array cref rhs) {
			if (this == &rhs)
				return (*this);

			const_cast<uint ref>(this->size()) = rhs.size();
			delete[] _array;
			_array = new T [_size];
			std::copy(rhs.data(), rhs.data() + rhs.size(), _array);
			return (*this);
		}

		~Array() {
			try {
				delete[] _array;
			} catch (...) {};
		}

		// Overloads
		T ref operator [] (const uint idx) {
			if (idx >= _size)
				throw std::out_of_range("");
			return _array[idx];
		}

		// Methods
		uint cref size() const {
			return (_size);
		}

		const T *data() const {
			return (_array);
		}

		// Accessors
		T *getArray() {
			return (_array);
		}

	private:
		const uint	_size;
		T			*_array;
};

#endif //ARRAY_H
