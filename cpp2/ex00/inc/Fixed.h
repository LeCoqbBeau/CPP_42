//
// Created by mscheman on 8/20/24.
//

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include "colors.h"

class Fixed {
	private:
		int					_num;
		static const int	_bits = 8;
	public:
		Fixed();
		Fixed(Fixed &src);
		Fixed& operator = (const Fixed &src);
		~Fixed();
		void	setRawBits(int raw);
		int		getRawBits();
};

#endif //FIXED_H
