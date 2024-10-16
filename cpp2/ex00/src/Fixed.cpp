//
// Created by mscheman on 8/20/24.
//

#include "Fixed.h"

Fixed::Fixed() {
	std::cout << BGRN "Default Constructor called" CLR;
	std::cout << BBLK " [ " << this << " ]" CLR << std::endl;
	_num = 0;
}

Fixed::Fixed(Fixed &src) {
	std::cout << BGRN "Copy constructor called" CLR;
	std::cout << BBLK " [ " << this << " ]" CLR << std::endl;
	this->_num = src._num;
}

Fixed& Fixed::operator=(const Fixed &src) {
	std::cout << BGRN "Copy assignment operator called" CLR;
	std::cout << BBLK " [ " << this << " ]" CLR << std::endl;
	this->_num = src._num;
	return *this;
}

int Fixed::getRawBits() {
	std::cout << BCYN "getRawBits() called" CLR;
	std::cout << BBLK " [ " << this << " ]" CLR << std::endl;
	return _num;
}

void Fixed::setRawBits(int raw) {
	std::cout << BCYN "setRawBits() called" CLR;
	std::cout << BBLK " [ " << this << " ]" CLR << std::endl;
	this->_num = raw;
}

Fixed::~Fixed() {
	std::cout << BRED "Destructor called" CLR;
	std::cout << BBLK " [ " << this << " ]" CLR << std::endl;
}

