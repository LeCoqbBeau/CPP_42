#ifndef SPAN_H
# define SPAN_H

# include <set>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <cstring>
# include <ctime>
# include <cstdlib>
# include <climits>
# include <iterator>

# include "utils.h"
# define TEMPLATE_T template <typename T>

class Span
{
	public:
		// Typedef
		typedef std::multiset<int>					container;
		typedef std::multiset<int>::const_iterator	const_iterator;

		// Orthodox Canonical Form
		Span(uint N = 0);
		Span(Span cref src);
		Span ref operator=(Span cref rhs);
		~Span();

		// Accessors
		container cref getList() const;
		uint cref getSize() const;

		// Methods
		void print() const;
		uint shortestSpan() const;
		uint longestSpan() const;
		void addNumber(int num);
		TEMPLATE_T void addNumber(T start, T end);
		void fillMemory();

	private:
		const uint	_size;
		container	_container;
};

// Template hihi
TEMPLATE_T void Span::addNumber(T start, T end) {
	// Shenanigans to make sure T is an iterator
	typedef typename std::iterator_traits<T>::difference_type difference_type;
	difference_type iWantToCompile;
	(void)iWantToCompile;
	//
	std::vector<typename std::iterator_traits<T>::value_type> temp(start, end);
	if (getList().size() + temp.size() > getSize())
		throw std::length_error("List is full");
	_container.insert(temp.begin(), temp.end());
}

#endif //SPAN
