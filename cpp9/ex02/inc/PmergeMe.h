//
// Created by mscheman on 10/26/24.
//

#ifndef PMERGEME_H
#define PMERGEME_H

#include <vector>
#include <deque>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <iomanip>

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cerrno>

#include "utils.h"

class PmergeMe {
	public:
		// Typedef
		typedef long					num;
		typedef std::pair<num, num>		pair;
		typedef std::vector<num>		vector;
		typedef std::deque<num>			deque;

		// Canonical Orthodox Form
		PmergeMe();
		PmergeMe(PmergeMe cref src);
		PmergeMe ref operator	= (PmergeMe cref rhs);
		~PmergeMe();

		// Methods
		void					push(num cref num);
		TEMPLATE_T T			sort(T container);
		TEMPLATE_T void			print(T cref container, str cref title);
		TEMPLATE_T bool			isSorted(T cref container);

		// Accessors
		vector cref				getVector() const;
		vector ref				getVector();
		deque cref				getDeque() const;
		deque ref				getDeque();

	private:
		// Sorting
		TEMPLATE_T T			_sort(T cref container, num size, num pairs);
		TEMPLATE_TU static void	_setPairs(T big, T small, U nums, U end);
		TEMPLATE_T static void	_insert(T ref sorted, T ref toInsert);
		TEMPLATE_T static void	_binaryInsert(T ref sorted, T ref toInsert, std::size_t cref pos);

		// Attributes
		vector					_vector;
		deque					_deque;
};

PmergeMe::pair	minmax(PmergeMe::num cref x, PmergeMe::num cref y);
std::size_t		getJacobsthal(uint idx);
void			printTime(clock_t cref start, clock_t cref end);

#include "PmergeMe.tpp"

#endif //PMERGEME_H
