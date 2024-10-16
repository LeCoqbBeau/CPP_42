//
// Created by mscheman on 8/19/24.
//

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <colors.h>
# include <string>
# include <iostream>

class Zombie {
	public:
		Zombie();
		Zombie(const std::string& name);
		~Zombie();
		void announce( void );
		void set_name(const std::string &name);
	private:
		std::string _name;
};

Zombie *zombieHorde( int N, std::string name );

#endif //ZOMBIE_H
