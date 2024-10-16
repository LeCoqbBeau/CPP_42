//
// Created by mscheman on 8/20/24.
//

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>
#include <climits>
#include "colors.h"

class Fixed {
	private:
		int					_num;
		static const int	_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed& operator = (const Fixed &src);
		Fixed(const float num);
		Fixed(const int num);
		~Fixed();

		bool operator > (const Fixed &rhs) const;
		bool operator < (const Fixed &rhs) const;
		bool operator >= (const Fixed &rhs) const;
		bool operator <= (const Fixed &rhs) const;
		bool operator == (const Fixed &rhs) const;
		bool operator != (const Fixed &rhs) const;

		Fixed operator + (const Fixed &add) const;
		Fixed operator - (const Fixed &sub) const;
		Fixed operator * (const Fixed &mul) const;
		Fixed operator / (const Fixed &div) const;

		Fixed operator ++ ();
		Fixed operator ++ (int);
		Fixed operator -- ();
		Fixed operator -- (int);

		void	setRawBits(int raw);
		int		getRawBits();
		float	toFloat() const;
		int		toInt() const;

		static	Fixed min(Fixed& num1, Fixed& num2);
		static	Fixed min(const Fixed& num1, const Fixed& num2);
		static	Fixed max(Fixed& num1, Fixed& num2);
		static	Fixed max(const Fixed& num1, const Fixed& num2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& Fixed);

#endif //FIXED_H
