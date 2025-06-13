//
// Created by lecoqbeau on 10/16/24.
//

#include "StockMarket.h"
#include "BitcoinExchange.h"

int main(int argc, char *argv[]) {
	(void)argc;

	StockMarket market;
	BitcoinExchange history;

	TRY_RETURN(market.loadData())
	TRY_RETURN(history.loadFile(argv[1]))
	TRY_RETURN(history.printValue(market))

	return (EXIT_SUCCESS);
}
