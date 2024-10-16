//
// Created by mscheman on 8/21/24.
//

#include "Point.h"

Point::Point() {
}

Point::Point(Fixed &x, Fixed &y) : _x(x), _y(y) {
}

Point::Point(const Point &src) : _x(src._x), _y(src._y) {
}

Point& Point::operator = (Point &cpy) {
	return cpy;
}

Point::~Point() {
}

Fixed &Point::getX() const {
	return (Fixed &)(_x);
}

Fixed &Point::getY() const {
	return (Fixed &)_y;
}

