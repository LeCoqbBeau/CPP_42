#include "Span.h"

static Span::const_iterator next(Span::const_iterator it);

// Canonical Orthodox Form
Span::Span(const uint N) : _size(N) {
	PRINT GRN BOLD "Span Parameterised Constructor called" CLR;
	PRINT " [ " AND this AND " ] " CENDL;
}

Span::Span(Span cref src) : _size(src.getSize()) {
	PRINT GRN BOLD "Span Copy Constructor called" CLR;
	PRINT " [ from " AND &src AND "to" AND this AND " ] " CENDL;
	_container = src._container;
}

Span ref Span::operator = (Span cref rhs) {
	PRINT GRN BOLD "Span Assignment Operator called" CLR;
	PRINT " [ from " AND &rhs AND "to" AND this AND " ] " CENDL;
	const_cast<uint ref>(_size) = rhs.getSize();
	_container = rhs._container;
	return *this;
}

Span::~Span() {
	RPRINT	str(YLW BOLD "Span Destructor called" CLR)
			.append(" [ ").append(TOSTR(this)).append(" ] " CLR) ENDL;
}

// Accessors
Span::container cref Span::getList() const {
	return _container;
}

uint cref Span::getSize() const {
	return _size;
}

// Methods
void Span::print() const {
	size_t	index = 0;
	for (const_iterator it = getList().begin(); it != getList().end(); ++it)
		PRINT BOLD AND ++index AND CLR ": " PRP BOLD AND *it CENDL;
}

uint Span::shortestSpan() const {
	if (getList().size() <= 1)
		throw std::logic_error("List is too small");
	int diff = INT_MAX;
	for (Span::const_iterator it = getList().begin(); it != (--getList().end()); ++it)
		(*next(it) - *it < diff ? (diff = *next(it) - *it) : true);
	return diff;
}

uint Span::longestSpan() const {
	if (getList().size() <= 1)
		throw std::logic_error("List is too small");
	return *(--getList().end()) - *(getList().begin());
}

void Span::addNumber(const int num) {
	if (getList().size() == getSize())
		throw std::length_error("List is full");
	_container.insert(num);
}

void Span::fillMemory() {
	while (getList().size() < getSize()) {
		_container.insert(std::rand());
	}
}

//
Span::const_iterator next(Span::const_iterator it) {
	return ++it;
}