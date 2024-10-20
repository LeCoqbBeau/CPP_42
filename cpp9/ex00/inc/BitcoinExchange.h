//
// Created by lecoqbeau on 10/20/24.
//

#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <fstream>
#include <iostream>
#include <map>

#include <climits>
#include <cstdlib>

#include "Date.h"
#include "StockMarket.h"

#include "colors.h"
#include "printUtils.h"

class BitcoinExchange {
public:
	// Typedef
	typedef std::multimap<t_date, float>::iterator iterator;
	typedef std::multimap<t_date, float>::const_iterator const_iterator;

	// Canonical Orthodox Form
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator = (const BitcoinExchange &rhs);

	// Iterators
	const_iterator cbegin() const;
	const_iterator cend() const;

	// Methods
	void loadFile(const std::string &filePath);
	void printValue(const StockMarket &market) const;

private:
	std::multimap<t_date, float> _wallet;
};

#endif //BITCOINEXCHANGE_H
