//
// Created by lecoqbeau on 10/20/24.
//

#include "BitcoinExchange.h"

// Canonical Orthofox Form
BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(BitcoinExchange cref src) {
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange cref rhs) {
	if (this == &rhs)
		return (*this);
	this->_wallet = rhs._wallet;
	return *this;
}

// Iterators
BitcoinExchange::const_iterator BitcoinExchange::cbegin() const {
	return _wallet.begin();
}

BitcoinExchange::const_iterator BitcoinExchange::cend() const {
	return _wallet.end();
}

// Methods
static t_date extractDate(str cref line);
static float extractAmount(str cref line);

void BitcoinExchange::loadFile(str cref filePath) {
	std::ifstream	file(filePath.c_str());
	std::string		line;
	t_date			tmpDate;
	float			tmpNum;

	if (!file.is_open())
		throw std::logic_error("Couldn't open the file");

	std::getline(file, line);
	if (line != "date | value")
		throw std::logic_error("File doesn't follow format \"date | format\"");

	while (!file.eof()) {
		std::getline(file, line);
		if (line.length() < 13 || line.at(11) != '|') {
			ERROR RED BOLD "Line doesn't follow format \"date | format\"" CENDL;
			ERROR TAB AND line CENDL;
			continue ;
		}
		TRY_OPER(tmpDate = extractDate(line),
			ERROR TAB AND line CENDL;
			continue;
		)
		TRY_OPER(tmpNum = extractAmount(line),
			ERROR TAB AND line CENDL;
			continue;
		)
		_wallet.insert(_wallet.end(), std::pair<t_date, float>(tmpDate, tmpNum));
	}
}

static t_date extractDate(str cref line) {
	int		year;
	int		month;
	int		day;
	char	*end;

	errno = 0;
	year = strtol(line.c_str(), &end, 10);
	if (errno == ERANGE || end[0] != '-')
		throw std::out_of_range("Invalid Year");
	month = strtol(&line.at(5), &end, 10);
	if (errno == ERANGE || end[0] != '-')
		throw std::out_of_range("Invalid Month");
	day = strtol(&line.at(8), &end, 10);
	if (errno == ERANGE || end[0] != ' ')
		throw std::out_of_range("Invalid Day");
	return t_date(year, month, day);
}

static float extractAmount(str cref line) {
	float	rate;
	char	*end;

	errno = 0;
	rate = strtof(&line.at(13), &end);
	if (errno == ERANGE || rate > 1000)
		throw std::overflow_error("Too much BTC");
	if (rate < 0)
		throw std::domain_error("Rate cannot be negative");
	if (end[0] != '\0')
		throw std::logic_error("Invalid line");
	return rate;
}

void BitcoinExchange::printValue(StockMarket cref market) const {
	for (BitcoinExchange::const_iterator it = cbegin(); it != cend(); ++it) {
		it->first.print();
		PRINT "=> " YLW BOLD AND it->second;
		PRINT CLR " = " GRN BOLD AND it->second * market[it->first] CENDL;
	}
}
