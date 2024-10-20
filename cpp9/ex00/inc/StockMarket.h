//
// Created by lecoqbeau on 10/20/24.
//

#ifndef STOCKMARKET_H
#define STOCKMARKET_H

#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>

#include <cstdlib>

#include "colors.h"
#include "printUtils.h"
#include "Date.h"

#define DATA_PATH "inc/data.csv"

class StockMarket {
public:
	// Typedef
	typedef std::map<t_date, float>::const_iterator const_iterator;

	// Canonical Orthodox Form
	StockMarket();
	StockMarket(const std::map<t_date, float> &prices);
	StockMarket(const StockMarket &src);
	StockMarket &operator=(const StockMarket &rhs);

	// Overload
	float operator[](const t_date &idx) const;

	// Methods
	void printMarket();
	float at(const t_date &date) const;

private:
	std::map<t_date, float> _prices;
	void _loadData();
};

#endif //STOCKMARKET_H
