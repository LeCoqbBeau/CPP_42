//
// Created by mscheman on 8/19/24.
//

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>
# include <iostream>

class Zombie {
	public:
		Zombie();
		Zombie(const std::string& name);
		~Zombie();
		void announce( void );
	private:
		std::string _name;
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif //ZOMBIE_H
