//
// Created by lecoqbeau on 10/20/24.
//

#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <fstream>
#include <map>
#include <climits>
#include <cstdlib>

#include "Date.h"
#include "StockMarket.h"

#include "utils.h"

class BitcoinExchange {
	public:
		// Typedef
		typedef std::multimap<t_date, float> container;
		typedef container::iterator iterator;
		typedef container::const_iterator const_iterator;

		// Canonical Orthodox Form
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange cref src);
		BitcoinExchange ref operator = (BitcoinExchange cref rhs);

		// Iterators
		const_iterator cbegin() const;
		const_iterator cend() const;

		// Methods
		void loadFile(str cref filePath);
		void printValue(StockMarket cref market) const;

	private:
		container _wallet;
};

#endif //BITCOINEXCHANGE_H
