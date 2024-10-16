//
// Created by mscheman on 8/16/24.
//

#include "PhoneBook.h"

PhoneBook::PhoneBook() {
	this->_next_contact_index = 0;
}

Contact PhoneBook::get_contact(int pos) {
	return (this->_contacts[pos]);
}

void PhoneBook::add() {
	this->_contacts[this->_next_contact_index].overwrite();
	std::cout << CLR_TERM << std::endl;
	std::cout << BCYN "Created contact \"" << this->_contacts[this->_next_contact_index].get_first() << "\"." CLR << std::endl;
	this->_next_contact_index++;
	this->_next_contact_index %= 8;
}

void PhoneBook::exit() {
	std::cout << RED "Turning off..." << std::endl;
}

static void			separator();
static void 		show_contact(Contact &contact, int pos);
static std::string	string_truncate(std::string str);
static bool			is_invalid_index(std::string &input, PhoneBook phoneBook);
static void			expose_contact(Contact &contact);

void PhoneBook::search() {

	if (this->_contacts[0].get_first().empty()) {
		std::cout << BPRP " But nobody came..." CLR << std::endl;
		return ;
	} ;

	Contact column_name("first name", "last name", "nickname", "digits", "");
	show_contact(column_name, -1);
	for (int i = 0; i < 8; ++i)
		show_contact(this->_contacts[i], i);
	separator();

	std::string	input;
	input = "";
	std::cout << BBLU << "Please select the concact's index." << BLU << std::endl;
	while (is_invalid_index(input, *this))
		std::getline(std::cin, input);
	expose_contact(this->_contacts[std::atoi(input.c_str())]);
}

static void show_contact(Contact &contact, int pos)
{
	separator();
	std::cout << " |";
	if (pos == -1)
		std::cout << "num";
	else
		std::cout << " " << pos << " ";
	std::cout << "|" << std::setw(10) << string_truncate(contact.get_first());
	std::cout << "|" << std::setw(10) << string_truncate(contact.get_last());
	std::cout << "|" << std::setw(10) << string_truncate(contact.get_nick());
	std::cout << "|" << std::setw(10) << string_truncate(contact.get_digit());
	std::cout << "|" << std::endl;
}

static void	separator()
{
	std::cout << " ⃝ " << "―――";
	std::cout << "⃝ " << "――――――――――";
	std::cout << "⃝ " << "――――――――――";
	std::cout << "⃝ " << "――――――――――";
	std::cout << "⃝ " << "――――――――――";
	std::cout << "⃝ " << std::endl;
}

static std::string string_truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9)) + ".";
	return (str);
}

static bool	is_invalid_index(std::string &input, PhoneBook phoneBook)
{
	if (input.empty() || input.length() > 1)
		return (true);
	if (input.find_first_not_of("01234567") != std::string::npos)
		return (true);

	int	index = std::atoi(input.c_str());

	if (phoneBook.get_contact(index).get_first().empty())
		return (true);
	return (false);
}

static void	expose_contact(Contact &contact)
{
	std::cout << std::endl;
	std::cout << GRN "Target : " BGRN << contact.get_first() << " " << contact.get_last() << GRN "." << std::endl;
	std::cout << GRN "\t- Undercover as : " BGRN << contact.get_nick() << GRN "." << std::endl;
	std::cout << GRN "\t- You can call him at : " BGRN << contact.get_digit() << GRN "." << std::endl;
	std::cout << GRN "\t- Known for : " BGRN << contact.get_secret() << GRN "." CLR << std::endl;
	std::cout << std::endl;
}
