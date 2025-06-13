
#pragma once

#include "PmergeMe.h"

TEMPLATE_T T PmergeMe::sort(T container) {
	print(container, CYN BOLD "Before:" CLR);
	const clock_t start = clock();
	T sorted = _sort(container, container.size(), std::ceil(container.size() / 2.f));
	const clock_t end = clock();
	printTime(start, end);
	const bool isContainerSorted = isSorted(sorted);
	PRINT (isContainerSorted ? GRN : RED);
	SHOW(isContainerSorted);
	PRINT CLR;
	print(sorted, CYN BOLD "After:" CLR);
	NEWL;
	return (sorted);
}

TEMPLATE_T void	PmergeMe::print(T cref container, str cref title) {
	int i = 0;
	str toPrint;
	toPrint.append(title);
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		const str numPtr = TOSTR(*it);
		toPrint.append(" ");
		if (i > 7) {
			toPrint.append("[...]");
			break ;
		}
		toPrint.append(numPtr);
		++i;
	}
	PRINT toPrint ENDL;
}

TEMPLATE_T T PmergeMe::_sort(T cref container, num size, num pairs) {
	T big(pairs);
	T small(pairs - (size % 2));
	_setPairs(big.begin(), small.begin(), container.begin(), container.begin() + size - (size % 2));
	if (size % 2)
		*big.rbegin() = *container.rbegin();
	if (!isSorted(big))
		big = _sort(big, big.size(), std::ceil(big.size() / 2.f));
	_insert(big, small);
	return (big);
}

TEMPLATE_TU void PmergeMe::_setPairs(T big, T small, U nums, U end) {
	for (; nums != end; nums += 2) {
		const pair pair = minmax(*(nums), *(nums + 1));
		*big = pair.first;
		*small = pair.second;
		++big;
		++small;
	}
}

TEMPLATE_T bool PmergeMe::isSorted(T cref container) {
	const typename T::const_iterator it = std::adjacent_find(
		container.begin(),
		container.end(),
		std::greater<num>()
	);
	if (it != container.end())
		return (false);
	return (true);
}

TEMPLATE_T void PmergeMe::_insert(T ref sorted, T ref toInsert) {
	std::size_t i, jacobIDX = 0;

	for (; toInsert.size() > getJacobsthal(jacobIDX); ++jacobIDX) {
		i = 0;
		while (getJacobsthal(jacobIDX) > i && i > getJacobsthal(jacobIDX - 1)) {
			_binaryInsert(sorted, toInsert, getJacobsthal(jacobIDX) - i);
			++i;
		}
	}
	while (!toInsert.empty())
		_binaryInsert(sorted, toInsert, 0);
}

TEMPLATE_T void PmergeMe::_binaryInsert(T ref sorted, T ref toInsert, std::size_t cref pos) {
	std::size_t left = 0;
	std::size_t right = sorted.size();
	std::size_t mid = pos;
	if (mid >= right)
		mid = left + (right - left) / 2;
	while (right > left) {
		if (sorted[mid] < (toInsert[pos]))
			left = mid + 1;
		else
			if (mid)
				right = mid - 1;
			else
				right = 0;
		mid = (left + right) / 2;
	}
	if (sorted[mid] < toInsert[pos])
		sorted.insert(sorted.begin() + mid + 1, (toInsert[pos]));
	else
		sorted.insert(sorted.begin() + mid, (toInsert[pos]));
	toInsert.erase(toInsert.begin());
}