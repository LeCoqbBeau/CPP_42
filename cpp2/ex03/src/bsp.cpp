//
// Created by mscheman on 8/21/24.
//

#include "Point.h"

static Fixed calculateTriangleArea(Point const a, Point const b, Point const c);

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed bigTriangleArea;
	Fixed smallTriangleAreas[3];
	Fixed zero(0);

	bigTriangleArea = calculateTriangleArea(a, b, c);
	smallTriangleAreas[0] = calculateTriangleArea(point, a, b);
	if (smallTriangleAreas[0] == zero)
		return (false);
	smallTriangleAreas[1] = calculateTriangleArea(point, b, c);
	if (smallTriangleAreas[1] == zero)
		return (false);
	smallTriangleAreas[2] = calculateTriangleArea(point, a, c);
	if (smallTriangleAreas[2] == zero)
		return (false);
	for (int i = 0; i < 3; ++i) {
		bigTriangleArea = bigTriangleArea - smallTriangleAreas[i];
		if (bigTriangleArea < zero)
			return (false);
	}
	return (true);
}

static Fixed calculateTriangleArea(Point const a, Point const b, Point const c)
{
	Fixed Area;
	Fixed zero(0);

	Area = (a.getX() * (b.getY() - c.getY()));
	Area = Area + (b.getX() * (c.getY() - a.getY()));
	Area = Area + (c.getX() * (a.getY() - b.getY()));
	Area = Area / 2;
	if (Area < zero)
		Area = Area * Fixed(-1);
	return (Area);
}