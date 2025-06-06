//
// Created by lecoqbeau on 10/16/24.
//

#include "ScalarConverter.h"

// Static member prototypes
static bool printPseudoLiteral(str cref input);
static bool isValidNum(str cref input);
static void charPrint(char c, bool undisplayable=false);
static bool isFloatInteger(float f);
static bool isCharPrintable(bool isInteger, int value);
static void intPrint(int i, bool undisplayable=false);
static void floatPrint(float f, bool undisplayable=false);
static void doublePrint(double d);

// Static public method
void ScalarConverter::convert(str cref input)
{
	if (printPseudoLiteral(input))
		return ;

	t_type litteralType = ScalarConverter::_identify(input);
	if (litteralType == E_TYPE_END) {
		ERROR RED BOLD "wrong inputs in 2025 is crazy :skull:" ENDL;
		return ;
	}

	void *data = ScalarConverter::_convert(input, litteralType);
	if (data == __nullptr) {
		ERROR RED BOLD "i am NOT cooking this input" ENDL;
		return ;
	}

	ScalarConverter::_print(data, litteralType);

	VOIDDEL (data);
}

// Canonical Orthodox Form
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter cref rhs) {
	(void)rhs;
}

ScalarConverter ref ScalarConverter::operator = (ScalarConverter cref rhs) {
	(void)rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

// Methods
t_type ScalarConverter::_identify(str cref input) {
	if (input.length() == 1)
		return CHAR;
	if (!isValidNum(input))
		return E_TYPE_END;
	if (input.find('.') == str::npos)
		return INT;
	if (input.find('f') != str::npos)
		return FLOAT;
	return DOUBLE;
}

static bool isValidNum(str cref input) {
	str::const_iterator	it = input.begin();
	bool				isInteger = true;

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

void *ScalarConverter::_convert(str cref input, const t_type type) {
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

void ScalarConverter::_print(void *value, const t_type type) {
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

static bool printPseudoLiteral(str cref input) {
	if (false
		|| input == "-inff"
		|| input == "-inf"
		|| input == "+inff"
		|| input == "+inf"
		|| input == "nanf"
		|| input == "nan"
	) {
		charPrint(0, true);
		intPrint(0, true);
		if (input == "-inff" || input == "-inf") {
			floatPrint(-__builtin_inff());
			doublePrint(-__builtin_inf());
		} else if (input == "+inff" || input == "+inf") {
			floatPrint(__builtin_inff());
			doublePrint(__builtin_inf());
		} else {
			floatPrint(__builtin_nan("0x7fc00000"));
			doublePrint(__builtin_nan("0x7fc00000"));
		}
		return true;
	}
	return false;
}

static void charPrint(const char c, const bool undisplayable) {
	PRINT TAB CYN BOLD "char: " CLR;
	if (undisplayable)
		PRINT PRP BOLD "Non displayable" CENDL;
	else if (isprint(c))
		PRINT '\'' AND c AND '\'' CENDL;
	else
		PRINT "Non printable" CENDL;
}

static bool isCharPrintable(const bool isInteger, const int value)
{
	if (!isInteger)
		return false;
	if (value > CHAR_MAX || value < CHAR_MIN)
		return false;
	if (!isprint(value))
		return false;
	return true;
}

static bool isFloatInteger(const float f) {
	if (f - static_cast<long>(f) != 0)
		return false;
	return true;
}

static void intPrint(const int i, const bool undisplayable) {
	PRINT TAB CYN BOLD "int: " CLR;
	if (undisplayable)
		PRINT PRP BOLD "Non displayable" CENDL;
	else
		PRINT i CENDL;
}

static void floatPrint(const float f, const bool undisplayable) {
	PRINT TAB CYN BOLD "float: " CLR;
	if (undisplayable)
		PRINT PRP BOLD "Non displayable" CENDL;
	else
	{
		if (isFloatInteger(f) && TOSTR(f).find('e') == str::npos)
			PRINT f AND ".0";
		else
			PRINT f;
		PRINT "f" ENDL;
	}
}

static void doublePrint(const double d) {
	PRINT TAB CYN BOLD "double: " CLR;
	PRINT d CENDL;
}
