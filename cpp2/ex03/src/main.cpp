//
// Created by mscheman on 8/16/24.
//

#include "Point.h"

int	main()
{
	Fixed x;
	Fixed y;

	x = Fixed(0);
	y = Fixed(0);
	Point a(x, y);

	x = Fixed(2);
	y = Fixed(7);
	Point b(x, y);

	x = Fixed(4);
	y = Fixed(1);
	Point c(x, y);

	x = Fixed(3);
	y = Fixed(2);
	Point p(x, y);

	std::cout << BCYN "The point p (" << p.getX() << "; " << p.getY() << ") ";
	if (bsp(a, b, c, p))
		std::cout << BGRN "is inside ";
	else
		std::cout << BRED "is outside ";
	std::cout << BCYN "the triangle." CLR << std::endl;
}
