//
// Created by mscheman on 8/20/24.
//

#include "Fixed.h"
#include <cstdlib>

Fixed::Fixed() {
	std::cout << BGRN "Default Constructor called" CLR;
	std::cout << BBLK " [ " << this << " ]" CLR << std::endl;
	this->_num = 0;
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
	this->_num = (int)roundf(num * (1 << _bits));
}

Fixed& Fixed::operator=(const Fixed &src) {
	std::cout << BGRN "Copy assignment operator called" CLR;
	std::cout << BBLK " [ " << this << " ]" CLR << std::endl;
	this->_num = src._num;
	return *this;
}

bool Fixed::operator>(const Fixed &rhs) const {
	if (this->_num > rhs._num)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &rhs) const {
	if (this->_num < rhs._num)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &rhs) const {
	if (this->_num >= rhs._num)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &rhs) const {
	if (this->_num <= rhs._num)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &rhs) const {
	if (this->_num == rhs._num)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &rhs) const {
	if (this->_num != rhs._num)
		return true;
	return false;
}

Fixed Fixed::operator + (const Fixed &add) const {
	Fixed	added;
	added._num = (this->_num + add._num);
	return added;
}

Fixed Fixed::operator - (const Fixed &sub) const {
	Fixed	substracted;
	substracted._num = (this->_num - sub._num);
	return substracted;
}

Fixed Fixed::operator * (const Fixed &mul) const {
	Fixed	multiplied;
	multiplied._num = (this->_num * mul._num) / (1 << _bits);
	return multiplied;
}

Fixed Fixed::operator / (const Fixed &div) const {
	if (div._num == 0)
	{
		std::cout << BRED "Division by 0... returning FIXED_MAX" CLR;
		std::cout << BBLK " [ " << this << " ] / [ " << &div << " ] ";
		std::cout << std::endl;
		Fixed exception;
		exception._num = INT_MAX;
		return (exception);
	}

	float calc;
	calc = this->toFloat();
	calc /= div.toFloat();

	Fixed divided(calc);
	return divided;
}

Fixed Fixed::operator ++ () {
	this->_num = this->_num + 1;
	return *this;
}

Fixed Fixed::operator ++ (int) {
	Fixed temp = *this;
	this->_num = this->_num + 1;
	return temp;
}

Fixed Fixed::operator -- () {
	this->_num = this->_num - 1;
	return *this;
}

Fixed Fixed::operator -- (int) {
	Fixed temp = *this;
	this->_num = this->_num - 1;
	return temp;
}

std::ostream& operator<<(std::ostream& os, const Fixed& Fixed) {
	os << Fixed.toFloat();
	return os;
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
	converted = converted / (1 << _bits);
	return (converted);
}

int Fixed::toInt() const {
	int	converted;

	converted = (int)roundf(this->toFloat());
	return (converted);
}

Fixed Fixed::min(Fixed &num1, Fixed &num2) {
	if (num1 > num2)
		return num2;
	return num1;
}

Fixed Fixed::min(const Fixed &num1, const Fixed &num2) {
	if (num1 > num2)
		return num2;
	return num1;
}

Fixed Fixed::max(Fixed &num1, Fixed &num2) {
	if (num1 > num2)
		return num1;
	return num2;
}

Fixed Fixed::max(const Fixed &num1, const Fixed &num2) {
	if (num1 > num2)
		return num1;
	return num2;
}

Fixed::~Fixed() {
	std::cout << BPRP "Destructor called" CLR;
	std::cout << BBLK " [ " << this << " ]" CLR << std::endl;
}
