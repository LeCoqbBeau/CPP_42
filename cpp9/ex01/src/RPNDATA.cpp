//
// Created by mscheman on 6/10/25.
//

# include "RPN.h"

s_rpnData::s_rpnData(const e_operator operator_, const float float_, const bool bool_)
	: op(operator_), num(float_), isOperator(bool_) {};

s_rpnData::s_rpnData(s_rpnData cref src) {
	*this = src;
}

s_rpnData ref s_rpnData::operator = (s_rpnData cref rhs) {
	if (this != &rhs) {
		op = rhs.op;
		num = rhs.num;
		isOperator = rhs.isOperator;
	}
	return *this;
};