#include "RPN.h"

#include <float.h>

// Protytpes
static float      getNum(const char c);
static e_operator getOp(char cref c);
static float      doCalculation(s_rpnData cref lhs, s_rpnData cref rhs, s_rpnData cref op);

// Canonical Orthodox Form
RPN::RPN() {}

RPN::RPN(container cref operations)
	: _operations(operations){}

RPN::RPN(RPN cref src) {
	*this = src;
}

RPN ref RPN::operator = (RPN cref rhs) {
	if (this != &rhs)
		setOperations(rhs.getOperations());
	return *this;
}

RPN::~RPN() {}

// Accessors
RPN::container cref RPN::getOperations() const {
	return _operations;
}

RPN::container ref RPN::getOperations() {
	return _operations;
}

void RPN::setOperations(container cref operations) {
	this->_operations = operations;
}

// Methods
void RPN::loadCalculation(str cref line) {
	s_rpnData	tmpData;

	for (str::const_iterator it = line.begin(); it != line.end(); ++it) {
		errno = 0;
		while (isspace(*it) && it != line.end()) ++it;
		if (it == line.end()) break;
		if (isdigit(*it))
			tmpData = s_rpnData(E_OPERATOR_END, getNum(*it));
		else
			tmpData = s_rpnData(getOp(*it), 0, true);
		getOperations().push(tmpData);
		if (tmpData.isOperator)
			_calculate();
	}
	if (getOperations().size() != 1)
		throw std::runtime_error("Calculation is not finished, missing operands or operators");
	NEWL;
	PRINT GRN BOLD "Result: " CLR AND getOperations().top().num AND CLR ENDL;
	getOperations().pop();
}

static float getNum(const char c) {
	return std::strtof(&c, 0);
}

static e_operator getOp(char cref c) {
	switch (c) {
		case ADD: return ADD;
		case SUB: return SUB;
		case MUL: return MUL;
		case DIV: return DIV;
		default:  throw std::invalid_argument("Invalid input");
	}
}

void RPN::_calculate() {
	s_rpnData	lhs;
	s_rpnData	rhs;
	s_rpnData	op;
	float		result;

	op = getOperations().top();
	getOperations().pop();
	rhs = getOperations().top();
	getOperations().pop();
	lhs = getOperations().top();
	getOperations().pop();
	result = doCalculation(lhs, rhs, op);
	PRINT " = " AND result AND CLR ENDL;
	getOperations().push(s_rpnData(E_OPERATOR_END, result));
}

static float doCalculation(s_rpnData cref lhs, s_rpnData cref rhs, s_rpnData cref op) {
	if (lhs.isOperator || rhs.isOperator)
		throw std::runtime_error("Invalid number");
	if (!op.isOperator)
		throw std::runtime_error("Invalid operator");
	switch (op.op) {
		case ADD:
			PRINT TAB AND lhs.num AND " + " AND rhs.num AND CLR;
			return lhs.num + rhs.num;
		case SUB:
			PRINT TAB AND lhs.num AND " - " AND rhs.num AND CLR;
			return lhs.num - rhs.num;
		case MUL:
			PRINT TAB AND lhs.num AND " * " AND rhs.num AND CLR;
			return lhs.num * rhs.num;
		case DIV:
			PRINT TAB AND lhs.num AND " / " AND rhs.num AND CLR;
			return lhs.num / rhs.num;
		default:
			throw std::runtime_error("Uninitialized operator");
	}
}

std::ostream ref operator << (std::ostream ref os, RPN cref rpn) {
	RPN::container iter = rpn.getOperations();
	while (!iter.empty())
	{
		if (!iter.top().isOperator)
			os AND iter.top().num;
		else {
			switch (iter.top().op) {
				case ADD:
					os AND "+";
					break;
				case SUB:
					os AND "-";
					break;
				case MUL:
					os AND "*";
					break;
				case DIV:
					os AND "/";
					break;
				case E_OPERATOR_END:
					throw std::runtime_error("Uninitialized operator");
			}
		}
		iter.pop();
		if (!iter.empty())
			os AND " ";
	}
	return os;
}
