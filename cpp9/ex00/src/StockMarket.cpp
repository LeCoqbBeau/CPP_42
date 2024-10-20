//
// Created by lecoqbeau on 10/20/24.
//

#include "StockMarket.h"

// Canonical Orthodox Form
StockMarket::StockMarket() {
	_loadData();
}

StockMarket::StockMarket(const std::map<t_date, float>& prices) {
	_prices = prices;
}

StockMarket::StockMarket(const StockMarket& src) {
	*this = src;
}

StockMarket& StockMarket::operator=(const StockMarket& rhs) {
	this->_prices = rhs._prices;
	return *this;
}

// Overload
float StockMarket::operator[](const t_date& idx) const {
	StockMarket::const_iterator it;
	for (it = _prices.begin(); it != _prices.end(); ++it) {
		if (it->first > idx)
			break;
	}
	return (it != _prices.end() ? it->second : (--_prices.end())->second);
}

// Methods
static t_date extractDate(std::string &line);
static float extractRate(std::string &line);

void StockMarket::_loadData() {
	std::ifstream	data(DATA_PATH);
	std::string		line;
	t_date			tmpDate;
	float			tmpRate;

	std::getline(data, line);
	while (!data.eof()) {
		std::getline(data, line);
		if (line.empty())
			continue;
		tmpDate = extractDate(line);
		tmpRate = extractRate(line);
		_prices.insert(_prices.end(), std::pair<t_date, float>(tmpDate, tmpRate));
	}
}

static t_date extractDate(std::string &line) {
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
	if (errno == ERANGE || end[0] != ',')
		throw std::out_of_range("Invalid Day");
	return t_date(year, month, day);
}

static float extractRate(std::string &line) {
	float	rate;
	char	*end;

	errno = 0;
	rate = strtof(&line.at(11), &end);
	if (errno == ERANGE)
		throw std::overflow_error("Rate is too big");
	if (end[0] != '\0')
		throw std::logic_error("Invalid Line");
	if (rate < 0)
		throw std::domain_error("Rate cannot be negative");
	return rate;
}

void StockMarket::printMarket() {
	for (StockMarket::const_iterator it = _prices.begin(); it != _prices.end(); ++it) {
		it->first.print();
		PRINT ": " BYLW AND it->second AND CLR ENDL;
	}
}

float StockMarket::at(const t_date& date) const {
	return (*this)[date];
}