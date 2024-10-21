#include "Span.h"

// Canonical Orthodox Form
Span::Span(int N) : _size(N) {
	PRINT BGRN "Span Parameterised Constructor called" CLR;
	PRINT BBLK " [ " AND this AND " ] " CLR ENDL;
}

Span::Span(const Span &src) : _size(src._size) {
	PRINT BGRN "Span Copy Constructor called" CLR;
	PRINT BBLK " [ from " AND &src AND "to" AND this AND " ] " CLR ENDL;
	_list = src._list;
}

Span &Span::operator=(const Span &rhs) {
	PRINT BGRN "Span Assignment Operator called" CLR;
	PRINT BBLK " [ from " AND &rhs AND "to" AND this AND " ] " CLR ENDL;
	_list = rhs._list;
	return *this;
}

Span::~Span() {
	PRINT BGRN "Span Destructor called" CLR;
	PRINT BBLK " [ " AND this AND " ] " CLR ENDL;
}

// Accessors
const std::list<int> &Span::getList() const {
	return _list;
}

// Methods
void Span::print() const {
	size_t	index;
	index = 0;
	for (t_intListIt it = _list.begin(); it != _list.end(); ++it)
		PRINT BBLK AND ++index AND CLR ": " BPRP AND *it AND CLR ENDL;
}

uint Span::shortestSpan() const {
	if (_list.size() < 1)
		THROW_LIST_TOO_SMALL;
	int	smallest = INT_MAX;
	int	second = INT_MAX;
	for (t_intListIt it = _list.begin(); it != _list.end() ; ++it) {
		if (*it < smallest) {
			second = smallest;
			smallest = *it;
		} else if (*it < second)
			second = *it;
	}
	return second - smallest;
}

uint Span::longestSpan() const {
	if (_list.size() < 1)
		THROW_LIST_TOO_SMALL;
	size_t diff = *std::max_element(_list.begin(), _list.end()) - *std::min_element(_list.begin(), _list.end());
	return diff;
}

void Span::addNumber(int num) {
	if (_list.size() == _size)
		THROW_LIST_FULL;
	_list.insert(_list.end(), num);
}

void Span::addNumber(const t_intListIt &start, const t_intListIt &end) {
	uint	size = 0;
	t_intListIt &copy = const_cast<t_intListIt &>(start);
	while (copy++ != end)
		size++;
	if (_list.size() + size > _size)
		THROW_LIST_FULL;
	_list.insert(_list.end(), start, end);
}

void Span::fillMemory() {
	int random;
	while (_list.size() < _size) {
		random = rand();
		_list.insert(_list.end(), random);
	}
}

