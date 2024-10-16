//
// Created by mscheman on 8/23/24.
//

#include "Character.h"

Character::Character() : _name("Him") {
	for (int i = 0; i < INV_SIZE; ++i) {
		this->_inventory[i] = __nullptr;
	}
	this->_materiaList = new MateriaList;
}

Character::Character(const std::string &name) : _name(name) {
	for (int i = 0; i < INV_SIZE; ++i) {
		this->_inventory[i] = __nullptr;
	}
	this->_materiaList = new MateriaList;
}

Character::~Character() {
	delete this->_materiaList;
}

std::string const &Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < INV_SIZE; ++i) {
		if (this->_inventory[i] != __nullptr)
			continue;
		this->_inventory[i] = m;
		this->_materiaList->append(m);
		return ;
	}
}

void Character::unequip(int idx) {
	if (this->_inventory[idx] == __nullptr)
		return ;
	this->_inventory[idx] = __nullptr;
}

void Character::use(int idx, ICharacter &target) {
	if (this->_inventory[idx] == __nullptr)
		return;
	this->_inventory[idx]->use(target);
}


