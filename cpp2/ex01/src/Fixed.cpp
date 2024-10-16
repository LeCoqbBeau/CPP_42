//
// Created by mscheman on 8/20/24.
//

#include "Fixed.h"

Fixed::Fixed() {
	std::cout << BGRN "Default Constructor called" CLR;
	std::cout << BBLK " [ " << this << " ]" CLR << std::endl;
	_num = 0;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << BGRN "Copy constructor called" CLR;
	std::cout << BBLK " [ " << this << " ]" CLR << std::endl;
	this->_num = src._num;
}

Fixed::Fixed(const float num) {
	std::cout << BGRN "Float constructor called" CLR;
	std::cout << BBLK " [ " << this << " ]" CLR << std::endl;
	this->_num = (int)roundf(num * powf(2, _bits));
}

Fixed::Fixed(const int num) {
	std::cout << BGRN "Int constructor called" CLR;
	std::cout << BBLK " [ " << this << " ]" CLR << std::endl;
	this->_num = (int)roundf(num * powf(2, _bits));
}

Fixed& Fixed::operator=(const Fixed &src) {
	std::cout << BGRN "Copy assignment operator called" CLR;
	std::cout << BBLK " [ " << this << " ]" CLR << std::endl;
	this->_num = src._num;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
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

float Fixed::toFloat() const {
	float converted;

	converted = (float)this->_num;
	converted = converted / powf(2, _bits);
	return (converted);
}

int Fixed::toInt() const {
	int	converted;

	converted = (int)roundf(this->toFloat());
	return (converted);
}

Fixed::~Fixed() {
	std::cout << BRED "Destructor called" CLR;
	std::cout << BBLK " [ " << this << " ]" CLR << std::endl;
}
