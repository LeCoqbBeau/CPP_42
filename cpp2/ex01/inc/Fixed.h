//
// Created by mscheman on 8/20/24.
//

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>
#include "colors.h"

class Fixed {
	private:
		int					_num;
		static const int	_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed(const float num);
		Fixed(const int num);
		~Fixed();
		
		Fixed& operator = (const Fixed &src);

		void	setRawBits(int raw);
		int		getRawBits();
		float	toFloat() const;
		int		toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& Fixed);

#endif //FIXED_H
