//
// Created by lecoqbeau on 10/16/24.
//

#include <iostream>
#include "colors.h"
#include "printUtils.h"

#include "StockMarket.h"
#include "BitcoinExchange.h"

int main(int argc, char *argv[]) {
	(void)argc;
	int	returnValue = 0;

	StockMarket *market;
	BitcoinExchange history;

	try {
		market = new StockMarket;
	} catch (std::exception &e) {
		ERROR BRED AND e.what() AND CLR ENDL;
		returnValue = 1;
		goto main_return;
	}

	try {
		history.loadFile(argv[1]);
	} catch (std::exception &e) {
		ERROR BRED AND e.what() AND CLR ENDL;
		returnValue = 1;
		goto end_of_main;
	}

	try {
		history.printValue(*market);;
	} catch (std::exception &e) {
		ERROR BRED AND e.what() AND CLR ENDL;
		returnValue = 1;
		goto end_of_main;
	}

end_of_main:
	delete market;
main_return:
	return (returnValue);
}