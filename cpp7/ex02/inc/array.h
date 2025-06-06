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
			data() = new T [size()];
		}

		Array(Array cref src) : _size(0), _array(__nullptr) {
			*this = src;
		}

		Array ref operator = (Array cref rhs) {
			if (this == &rhs)
				return (*this);

			const_cast<uint ref>(size()) = rhs.size();
			delete[] data();
			data() = new T [size()];
			std::copy(rhs.data(), rhs.data() + rhs.size(), data());
			return (*this);
		}

		~Array() {
			try {
				delete[] data();
			} catch (...) {};
		}

		// Overloads
		T ref operator [] (const uint idx) {
			if (idx >= _size)
				throw std::out_of_range("");
			return data(idx);
		}

		T cref operator [] (const uint idx) const {
			if (idx >= _size)
				throw std::out_of_range("");
			return data(idx);
		}

		// Accessors
		uint cref size() const {
			return (_size);
		}

		T *data() {
			return (_array);
		}

		T data(uint index) {
			return (data()[index]);
		}

	private:
		const uint	_size;
		T			*_array;
};

#endif //ARRAY_H
