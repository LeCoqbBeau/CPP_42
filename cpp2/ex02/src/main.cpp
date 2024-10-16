//
// Created by mscheman on 8/16/24.
//

#include "Fixed.h"

int	main()
{
	Fixed a;
	Fixed const b( Fixed( 41.7578f ) / Fixed( 0 ) );
	std::cout << b << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}
