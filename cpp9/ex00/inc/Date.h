//
// Created by lecoqbeau on 10/20/24.
//

#ifndef DATE_H
# define DATE_H

# include <stdexcept>

# include "utils.h"

typedef unsigned int uint;

typedef struct s_date {
	// Constructor
	s_date(uint year = 0, uint month = 1, uint day = 1);

	// Static
	static uint maxDays[12];

	// Overload Relational Operators
	bool operator == (s_date cref rhs) const;
	bool operator != (s_date cref rhs) const;
	bool operator > (s_date cref rhs) const;
	bool operator >= (s_date cref rhs) const;
	bool operator < (s_date cref rhs) const;
	bool operator <= (s_date cref rhs) const;

	// Methods
	void print() const;

	// Attributes
	uint year;
	uint month;
	uint day;
}	t_date;

#endif //DATE_H
