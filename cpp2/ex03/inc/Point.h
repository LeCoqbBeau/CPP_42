//
// Created by mscheman on 8/21/24.
//

#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point {
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();
		Point(Fixed &x, Fixed &y);
		Point(const Point &src);
		Point& operator = (Point &cpy);
		~Point();
		Fixed &getX() const;
		Fixed &getY() const;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif //POINT_H
