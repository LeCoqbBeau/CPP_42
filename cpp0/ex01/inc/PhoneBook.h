//
// Created by mscheman on 8/16/24.
//

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"
# include <iomanip>

# define CLR_TERM "\033[2J\033[H"

class PhoneBook {
	public:
		PhoneBook();
		void	add();
		void	search();
		void	exit();
		Contact	get_contact(int pos);

	private:
		Contact	_contacts[8];
		int		_next_contact_index;
};


#endif
