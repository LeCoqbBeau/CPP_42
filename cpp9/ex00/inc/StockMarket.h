//
// Created by lecoqbeau on 10/20/24.
//

#ifndef STOCKMARKET_H
#define STOCKMARKET_H

#include <fstream>
#include <map>
#include <iomanip>
#include <cstdlib>

#include "utils.h"
#include "Date.h"

#define DATA_PATH "inc/data.csv"

class StockMarket {
	public:
		// Typedef
		typedef std::map<t_date, float> container;
		typedef container::const_iterator const_iterator;

		// Canonical Orthodox Form
		StockMarket();
		StockMarket(container cref prices);
		StockMarket(StockMarket cref src);
		StockMarket ref operator = (StockMarket cref rhs);

		// Overload
		float operator [] (t_date cref idx) const;

		// Methods
		void printMarket();
		float at(t_date cref date) const;
		void loadData();

	private:
		container _prices;
};

#endif //STOCKMARKET_H
