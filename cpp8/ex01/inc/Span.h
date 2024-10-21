#ifndef SPAN_H
# define SPAN_H

# include <list>
# include <algorithm>
# include <iostream>
# include <stdexcept>

#include <cstring>
#include <ctime>
#include <cstdlib>
#include <climits>

# include "colors.h"
# include "printUtils.h"

# define THROW_LIST_FULL throw std::length_error("List is full")
# define THROW_LIST_TOO_SMALL throw std::logic_error("List is too small")

typedef unsigned int uint;
typedef std::list<int>::const_iterator t_intListIt;
typedef std::list<int>::const_reverse_iterator t_intListRevIt;

class Span
{
public:
	// Orthodox Canonical Form
	Span(int N);
	Span(const Span &src);
	Span&operator=(const Span &rhs);
	~Span();

	// Accessors
	const std::list<int> &getList() const;

	// Methods
	void print() const;
	uint shortestSpan() const;
	uint longestSpan() const;
	void addNumber(int num);
	void addNumber(const t_intListIt &start, const t_intListIt &end);
	void fillMemory();

private:
	const uint _size;
	std::list<int> _list;
};

#endif //SPAN
