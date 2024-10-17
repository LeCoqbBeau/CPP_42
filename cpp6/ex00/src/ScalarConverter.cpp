//
// Created by lecoqbeau on 10/16/24.
//

#include "ScalarConverter.h"

static bool printPseudoLitteral(const std::string &input);

void Serialize::convert(const std::string& input)
{
	if (printPseudoLitteral(input))
		return ;

	t_type litteralType = Serialize::identify(input);
	if (litteralType == E_TYPE_END) {
		ERROR BRED "wrong inputs in 2024 is crazy :skull:" ENDL;
		return ;
	}

	void *data = Serialize::convert(input, litteralType);
	if (data == 0) {
		ERROR BRED "i am NOT cooking this input" ENDL;
		return ;
	}

	Serialize::print(data, litteralType);

	VOIDDEL (data);
}

// Canonical Orthodox Form
Serialize::Serialize() {}

Serialize::Serialize(const Serialize& rhs) {
	(void)rhs;
}

Serialize Serialize::operator=(const Serialize& rhs) {
	(void)rhs;
	return (*this);
}

Serialize::~Serialize() {}

// Methods
static bool isValidNum(const std::string &input);

t_type Serialize::identify(const std::string& input) {
	if (input.find_first_of(LOWER_ALPHABET UPPER_ALPHABET) != std::string::npos
		&& input.length() == 1)
		return CHAR;
	if (!isValidNum(input))
		return E_TYPE_END;
	if (input.find('.') == std::string::npos)
		return INT;
	if (input.find('f') != std::string::npos)
		return FLOAT;
	return DOUBLE;
}

static bool isValidNum(const std::string &input) {
	std::string::const_iterator it = input.begin();
	bool						isInteger = true;

	if (*it == '+' || *it == '-')
		++it;
	while (it < input.end()) {
		if (!isdigit(*it)
			&& !(isInteger && *it == '.')
			&& !(*it == 'f' && it + 1 == input.end()))
			return false;
		if (isInteger && *it == '.')
			isInteger = false;
		++it;
	}
	return true;
}

void* Serialize::convert(const std::string& input, t_type type)
{
	void *data;
	char charData;
	long integerData;
	double floatData;

	switch (type) {
	case CHAR:
		charData = input.at(0);
		data = new char;
		static_cast<char *>(data)[0] = charData;
		break;
	case INT:
		integerData = std::strtol(input.c_str(), 0, 10);
		if (integerData > INT_MAX || integerData < INT_MIN
			|| errno == ERANGE)
			return (0);
		data = new int;
		static_cast<int *>(data)[0] = integerData;
		break;
	case FLOAT:
		floatData = std::strtod(input.c_str(), 0);
		if (floatData > FLT_MAX || floatData < FLT_MIN
			|| errno == ERANGE)
			return (0);
		data = new float;
		static_cast<float *>(data)[0] = floatData;
		break;
	case DOUBLE:
		floatData = std::strtod(input.c_str(), 0);
		if (errno == ERANGE)
			return (0);
		data = new double;
		static_cast<double *>(data)[0] = floatData;
		break;
	case E_TYPE_END:
		return (0);
		break;
	}
	return data;
}

static void charPrint(char c, bool undisplayable=false);
static bool isFloatInteger(float f);
static bool isCharPrintable(bool isInteger, int value);
static void intPrint(int i, bool undisplayable=false);
static void floatPrint(float f, bool undisplayable=false);
static void doublePrint(double d);

void Serialize::print(void *value, t_type type)
{
	char charValue;
	int intValue;
	float floatValue;
	double doubleValue;

	switch (type) {
	case CHAR:
		charValue = static_cast<char *>(value)[0];
		charPrint(charValue);
		intPrint(static_cast<int>(charValue));
		floatPrint(static_cast<float>(charValue));
		doublePrint(static_cast<double>(charValue));
		break;
	case INT:
		intValue = static_cast<int *>(value)[0];
		charPrint(static_cast<char>(intValue), !isCharPrintable(true, intValue));
		intPrint(intValue);
		floatPrint(static_cast<float>(intValue));
		doublePrint(static_cast<double>(intValue));
		break;
	case FLOAT:
		floatValue = static_cast<float *>(value)[0];
		charPrint(static_cast<char>(floatValue),
			!isCharPrintable(isFloatInteger(floatValue), floatValue));
		intPrint(static_cast<int>(floatValue),
				!(isFloatInteger(floatValue) && floatValue <= (float)INT_MAX && floatValue >= INT_MIN));
		floatPrint(floatValue);
		doublePrint(static_cast<double>(floatValue));
		break;
	case DOUBLE:
		doubleValue = static_cast<double *>(value)[0];
		charPrint(static_cast<char>(doubleValue),
			!isCharPrintable(isFloatInteger(doubleValue), doubleValue));
		intPrint(static_cast<int>(doubleValue),
				!(isFloatInteger(doubleValue) && doubleValue <= INT_MAX && doubleValue >= INT_MIN));
		floatPrint(static_cast<float>(doubleValue),
			!(doubleValue <= FLT_MAX && doubleValue >= FLT_MIN));
		doublePrint(doubleValue);
		break;
	case E_TYPE_END:
		return ;
		break;
	}
}

static bool printPseudoLitteral(const std::string &input) {
	if (input == "-inff" || input == "+inff")
	{
		charPrint(0, true);
		intPrint(0, true);
		if (input == "-inff") {
			floatPrint(-__builtin_inff());
			doublePrint(-__builtin_inf());
		} else {
			floatPrint(__builtin_inff());
			doublePrint(__builtin_inf());
		}
		return true;
	}
	if (input == "-inf" || input == "+inf" || input == "nan")
	{
		charPrint(0, true);
		intPrint(0, true);
		floatPrint(0,true);
		if (input == "-inf")
			doublePrint(-__builtin_inf());
		else if (input == "+inf")
			doublePrint(__builtin_inf());
		else
			doublePrint(__builtin_nan("0x7fc00000"));
		return true;
	}
	return false;
}

static void charPrint(char c, bool undisplayable) {
	PRINT TAB BCYN "char: " CLR;
	if (undisplayable)
		PRINT BPRP "Non displayable" CLR ENDL;
	else
		PRINT c AND CLR ENDL;
}

static bool isCharPrintable(bool isInteger, int value)
{
	if (!isInteger)
		return false;
	if (value > CHAR_MAX || value < CHAR_MIN)
		return false;
	if (!isprint(value))
		return false;
	return true;
}

static bool isFloatInteger(float f) {
	if (f - static_cast<long>(f) != 0)
		return false;
	return true;
}

static void intPrint(int i, bool undisplayable) {
	PRINT TAB BCYN "int: " CLR;
	if (undisplayable)
		PRINT BPRP "Non displayable" CLR ENDL;
	else
		PRINT i AND CLR ENDL;
}

static void floatPrint(float f, bool undisplayable) {
	PRINT TAB BCYN "float: " CLR;
	if (undisplayable)
		PRINT BPRP "Non displayable" CLR ENDL;
	else
	{
		if (isFloatInteger(f))
			PRINT f AND ".0";
		else
			PRINT f;
		PRINT "f" ENDL;
	}
}

static void doublePrint(double d) {
	PRINT TAB BCYN "double: " CLR;
	PRINT d AND CLR ENDL;
}
