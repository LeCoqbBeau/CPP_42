#ifndef RPN_H
# define RPN_H

# include <iostream>
# include <string>
# include <stdexcept>
# include <stack>

# include <cerrno>
# include <climits>
# include <cstdlib>

# include "printUtils.h"
# include "colors.h"

enum e_operator {
	ADD = '+',
	SUB = '-',
	MUL = '*',
	DIV = '/',
	E_OPERATOR_END = 'X'
};

struct s_rpnData {
	s_rpnData() : op(E_OPERATOR_END), num(0), isOperator(true) {};
	s_rpnData(const long &data) : op(E_OPERATOR_END), num(data), isOperator(false) {};
	s_rpnData(const e_operator &data) : op(data), num(0), isOperator(true) {};
	s_rpnData &operator=(const s_rpnData &rhs) { op = rhs.op; num = rhs.num; isOperator = rhs.isOperator; return *this; };
	e_operator	op;
	long		num;
	bool		isOperator;
};

class RPN
{
public:
	// Orthodox Canonical Form
	RPN();
	RPN(const std::stack<s_rpnData> &_operations);
	RPN(const RPN &src);
	RPN&operator=(const RPN &rhs);
	~RPN();

	// Accessors
	const std::stack<s_rpnData> &getOperations() const;
	void setOperations(const std::stack<s_rpnData> &_operations);

	// Methods
	void loadCalculation(const std::string &line);

private:
	std::stack<s_rpnData> _operations;
	void _calculate();
};

std::ostream &operator<<(std::ostream &os, const RPN &rpn);

#endif //RPN
