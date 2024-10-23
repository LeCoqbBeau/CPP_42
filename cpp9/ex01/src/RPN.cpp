#include "RPN.h"

// Canonical Orthodox Form
RPN::RPN() {}

RPN::RPN(const std::stack<s_rpnData> &_operations) {
	this->_operations = _operations;
}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN &RPN::operator=(const RPN &rhs) {
	this->_operations = rhs._operations;
	return *this;
}

RPN::~RPN() {}

// Accessors
const std::stack<s_rpnData>& RPN::getOperations() const {
	return this->_operations;
}

void RPN::setOperations(const std::stack<s_rpnData> &operations) {
	this->_operations = operations;
}

// Methods
static long			getNum(std::string::const_iterator &it);
static e_operator	getOp(std::string::const_iterator &it);

void RPN::loadCalculation(const std::string &line) {
	s_rpnData	tmpData;

	for (std::string::const_iterator it = line.begin(); it < line.end(); ++it) {
		errno = 0;
		if (isdigit(*it))
			tmpData = s_rpnData(getNum(it));
		else
			tmpData = s_rpnData(getOp(it));
		_operations.push(tmpData);
		if (tmpData.isOperator)
			_calculate();
	}
	if (_operations.size() != 1)
		throw std::runtime_error("Calculation is not finished, missing operands or operators");
	PRINT BCYN "Result: " CLR AND _operations.top().num AND CLR ENDL;
	_operations.pop();
}

static long getNum(std::string::const_iterator &it) {
	char		*end;
	long		num;

	num = std::strtol(it.base(), &end, 10);
	if (end[0] != ' ' && end[0] != '\0')
		throw std::invalid_argument("Invalid input");
	if (errno == ERANGE && num == LONG_MAX)
		throw std::overflow_error("Number is too big");
	if (errno == ERANGE && num == LONG_MIN)
		throw std::underflow_error("Number is too small");
	while (*it != *end)
		++it;
	return (num);
}

static e_operator getOp(std::string::const_iterator &it) {
	e_operator	op;

	switch (*it) {
		case ADD:
			op = ADD;
			break;
		case SUB:
			op = SUB;
			break;
		case MUL:
			op = MUL;
			break;
		case DIV:
			op = DIV;
			break;
		default:
			throw std::invalid_argument("Invalid input");
	}
	++it;
	return op;
}

static long doCalculation(s_rpnData &lhs, s_rpnData &rhs, s_rpnData &op);

void RPN::_calculate() {
	s_rpnData	lhs;
	s_rpnData	rhs;
	s_rpnData	op;
	long		result;

	op = _operations.top();
	_operations.pop();
	rhs = _operations.top();
	_operations.pop();
	lhs = _operations.top();
	_operations.pop();
	result = doCalculation(lhs, rhs, op);
	PRINT BBLK " = " AND result AND CLR ENDL;
	_operations.push(s_rpnData(result));
}

static long doCalculation(s_rpnData &lhs, s_rpnData &rhs, s_rpnData &op) {
	if (lhs.isOperator || rhs.isOperator)
		throw std::runtime_error("Invalid number");
	if (!op.isOperator)
		throw std::runtime_error("Invalid operator");
	switch (op.op) {
		case ADD:
			PRINT BBLK AND lhs.num AND " + " AND rhs.num AND CLR;
			return lhs.num + rhs.num;
		case SUB:
			PRINT BBLK AND lhs.num AND " - " AND rhs.num AND CLR;
			return lhs.num - rhs.num;
		case MUL:
			PRINT BBLK AND lhs.num AND " * " AND rhs.num AND CLR;
			return lhs.num * rhs.num;;
		case DIV:
			PRINT BBLK AND lhs.num AND " / " AND rhs.num AND CLR;
			return lhs.num / rhs.num;;
		case E_OPERATOR_END:
			throw std::runtime_error("Uninitialized operator");
	}
}

std::ostream &operator<<(std::ostream &os, const RPN &rpn) {
	std::stack<s_rpnData> iter = rpn.getOperations();
	while (!iter.empty())
	{
		if (!iter.top().isOperator)
			os << iter.top().num;
		else {
			switch (iter.top().op) {
				case ADD:
					os << "+";
					break;
				case SUB:
					os << "-";
					break;
				case MUL:
					os << "*";
					break;
				case DIV:
					os << "/";
					break;
				case E_OPERATOR_END:
					throw std::runtime_error("Uninitialized operator");
			}
		}
		iter.pop();
		if (!iter.empty())
			os << " ";
	}
	return os;
}
