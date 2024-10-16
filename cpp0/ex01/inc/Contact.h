//
// Created by mscheman on 8/16/24.
//

#ifndef CONTACT_H
# define CONTACT_H

# include <string>
# include <iostream>
# include <cctype>
# include <cstdlib>
# include "colors.h"

class Contact {
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_secret;
		std::string	_phone_number;
	public:
		Contact();
		Contact(const std::string &first, const std::string &last, const std::string &nick, const std::string &digit, const std::string &secret);
		void		overwrite();
		std::string	get_first();
		std::string	get_last();
		std::string	get_nick();
		std::string	get_digit();
		std::string get_secret();
};

#endif
