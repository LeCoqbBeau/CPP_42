//
// Created by lecoqbeau on 10/20/24.
//

#include "Date.h"

// Static Members
uint t_date::maxDays[12] = {
	31, // JANUARY
	28, // FEBRUARY
	31, // MARCH
	30, // APRIL
	31, // MAY
	30, // JUNE
	31, // JULY
	31, // AUGUST
	30, // SEPTEMBER
	31, // OCTOBER
	30, // NOVEMBER
	31, // DECEMBER
};

// Constructor
s_date::s_date(const uint year, const uint month, const uint day) {
	if (month == 0 || month > 12)
		throw std::out_of_range("Invalid month");
	if (day == 0
		|| (day > maxDays[month - 1]
		&& (month == 2 && (year % 4 == 0) && day > maxDays[month - 1] + 1)))
		throw std::out_of_range("Invalid day");
	this->year = year;
	this->month = month;
	this->day = day;
}

// Overload Relational Operators
bool s_date::operator == (s_date cref rhs) const {
	if (this->year != rhs.year)
		return false;
	if (this->month != rhs.month)
		return false;
	if (this->day != rhs.day)
		return false;
	return true;
}

bool s_date::operator != (s_date cref rhs) const {
	if (this->year != rhs.year)
		return true;
	if (this->month != rhs.month)
		return true;
	if (this->day != rhs.day)
		return true;
	return false;
}

bool s_date::operator > (s_date cref rhs) const {
	if (this->year != rhs.year)
		return this->year > rhs.year;
	if (this->month != rhs.month)
		return this->month > rhs.month;
	if (this->day != rhs.day)
		return this->day > rhs.day;
	return false;
}

bool s_date::operator >= (s_date cref rhs) const {
	if (this->year != rhs.year)
		return this->year > rhs.year;
	if (this->month != rhs.month)
		return this->month > rhs.month;
	if (this->day != rhs.day)
		return this->day > rhs.day;
	return true;
}

bool s_date::operator < (s_date cref rhs) const {
	if (this->year != rhs.year)
		return this->year < rhs.year;
	if (this->month != rhs.month)
		return this->month < rhs.month;
	if (this->day != rhs.day)
		return this->day < rhs.day;
	return false;
}

bool s_date::operator <= (s_date cref rhs) const {
	if (this->year != rhs.year)
		return this->year < rhs.year;
	if (this->month != rhs.month)
		return this->month < rhs.month;
	if (this->day != rhs.day)
		return this->day < rhs.day;
	return true;
}

// Methods
void s_date::print() const {
	PRINT " [ " AND this->year AND "-";
	PRINT std::setfill('0') AND std::setw(2) AND this->month;
	std::flush(std::cout);
	PRINT "-";
	PRINT std::setfill('0') AND std::setw(2) AND this->day;
	std::flush(std::cout);
	PRINT " ] " CLR;
}