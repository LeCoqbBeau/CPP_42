//
// Created by mscheman on 10/26/24.
//

#include "PmergeMe.h"

// Canonical Orthodox Form
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe cref src) {
	*this = src;
}

PmergeMe ref PmergeMe::operator = (PmergeMe cref rhs) {
	if (this != &rhs) {
		this->_vector = rhs._vector;
		this->_deque = rhs._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

// Public Methods
void PmergeMe::push(num cref num) {
	_vector.push_back(num);
	_deque.push_back(num);
}

// Accessors
PmergeMe::vector cref PmergeMe::getVector() const {
	return _vector;
}

PmergeMe::vector ref PmergeMe::getVector() {
	return _vector;
}

PmergeMe::deque cref PmergeMe::getDeque() const {
	return _deque;
}

PmergeMe::deque ref PmergeMe::getDeque() {
	return _deque;
}

// Static functions
PmergeMe::pair minmax(PmergeMe::num cref x, PmergeMe::num cref y) {
	if (x > y)
		return std::make_pair(x, y);
	return std::make_pair(y, x);
}

std::size_t getJacobsthal(const uint idx) {
	std::vector<std::size_t> jacobNumber;
	if (jacobNumber.empty()) {
		jacobNumber.push_back(0);
		jacobNumber.push_back(1);
		for (int i = 2; i < 30; ++i)
			jacobNumber.push_back(jacobNumber[i - 1] + 2 * jacobNumber[i - 2]);
	}
	if (idx >= jacobNumber.size())
		for (uint i = jacobNumber.size() - 1; i <= idx; ++i)
			jacobNumber.push_back(jacobNumber[i - 1] + 2 * jacobNumber[i - 2]);
	return jacobNumber[idx];
}

void printTime(clock_t cref start, clock_t cref end) {
	const double time = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
	PRINT BOLD "Took " CLR AND std::setprecision(3);
	if (time > 1)
		PRINT RGB(224, 7, 7) BOLD AND time AND " ";
	else if (time * 1e3 > 1)
		PRINT RGB(224, 152, 7) BOLD AND time * 1e3 AND " milli";
	else if (time * 1e6 > 1)
		PRINT RGB(152, 224, 7) BOLD AND time * 1e6 AND " micro";
	else
		PRINT RGB(7, 224, 7) BOLD AND time * 1e9 AND " nano";
	PRINT CLR BOLD "seconds" CENDL;
}
