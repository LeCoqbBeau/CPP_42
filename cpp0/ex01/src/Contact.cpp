//
// Created by mscheman on 8/16/24.
//

#include "Contact.h"

static std::string	string_input(const std::string &message, bool (*check)(std::string&));
static bool			is_string_empty(std::string &string);
static bool			is_phone_number_invalid(std::string &number);

Contact::Contact() {
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone_number = "";
	this->_secret = "";
}

Contact::Contact(const std::string &first, const std::string &last, const std::string &nick, const std::string &digit, const std::string &secret) {
	this->_first_name = first;
	this->_last_name = last;
	this->_nickname = nick;
	this->_phone_number = digit;
	this->_secret = secret;
}

std::string Contact::get_first() {
	return (this->_first_name);
}

std::string Contact::get_last() {
	return (this->_last_name);
}

std::string Contact::get_nick() {
	return (this->_nickname);
}

std::string Contact::get_digit() {
	return (this->_phone_number);
}

std::string Contact::get_secret() {
	return (this->_secret);
}

void Contact::overwrite() {
	this->_first_name = string_input("Please enter the contact's name.", is_string_empty);
	this->_last_name = string_input("Please enter " + this->_first_name + "'s last name.", is_string_empty);
	this->_nickname = string_input("Please enter " + this->_first_name + "'s nickname.", is_string_empty);
	this->_phone_number = string_input("Please enter " + this->_first_name + "'s digits.", is_phone_number_invalid);
	this->_secret = string_input("Please enter " + this->_first_name + "'s darkest secret.", is_string_empty);
}

static std::string	string_input(const std::string &message, bool (*check)(std::string&))
{
	std::string	input;

	input = "";
	std::cout << BBLU << message << BLU << std::endl;
	while (check(input))
		std::getline(std::cin, input);
	std::cout << CLR;
	return (input);
}

static bool	is_string_empty(std::string &string)
{
	return (string.empty());
}

static bool	is_phone_number_invalid(std::string &number)
{
	if (number.empty())
		return (true);
	if (number.length() != 10)
		return (true);
	if (number.find_first_not_of("0123456789") != std::string::npos)
		return (true);
	return (false);
}
