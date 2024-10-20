//
// Created by lecoqbeau on 10/20/24.
//

#ifndef DATE_H
# define DATE_H

# include <iostream>
# include <iomanip>
# include <stdexcept>

# include "colors.h"
# include "printUtils.h"

typedef unsigned int uint;

typedef struct s_date {
	// Constructor
	s_date();
	s_date(uint year, uint month, uint day);

	// Static
	static const s_date dateNull;


	// Overload Relational Operators
	bool operator == (const s_date &rhs) const;
	bool operator != (const s_date &rhs) const;
	bool operator > (const s_date &rhs) const;
	bool operator >= (const s_date &rhs) const;
	bool operator < (const s_date &rhs) const;
	bool operator <= (const s_date &rhs) const;

	// Methods
	void print() const;

	// Attributes
	uint year;
	uint month;
	uint day;
}	t_date;

static const s_date dateNull = t_date();

#endif //DATE_H
