#ifndef RPN_H
# define RPN_H

# include <stdexcept>
# include <stack>

# include <cerrno>
# include <climits>
# include <cstdlib>

# include "utils.h"

enum e_operator {
	ADD = '+',
	SUB = '-',
	MUL = '*',
	DIV = '/',
	E_OPERATOR_END = 'X'
};

struct s_rpnData {
	s_rpnData(e_operator = E_OPERATOR_END, float = 0, bool = false);
	s_rpnData(s_rpnData cref src);
	s_rpnData ref operator = (s_rpnData cref rhs);
	e_operator	op;
	float		num;
	bool		isOperator;
};

class RPN {
	public:
		// Typedef
		typedef std::stack<s_rpnData> container;

		// Orthodox Canonical Form
		RPN();
		RPN(container cref operations);
		RPN(RPN cref src);
		RPN ref operator = (RPN cref rhs);
		~RPN();

		// Accessors
		container cref getOperations() const;
		container ref getOperations();
		void setOperations(container cref operations);

		// Methods
		void loadCalculation(str cref line);

	private:
		container	_operations;
		void		_calculate();
};

std::ostream ref operator << (std::ostream ref os, RPN cref rpn);

#endif //RPN
