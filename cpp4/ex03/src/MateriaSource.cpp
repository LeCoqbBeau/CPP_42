//
// Created by mscheman on 8/26/24.
//

#include "MateriaSource.h"

MateriaSource::MateriaSource() {
	for (int i = 0; i < INV_SIZE; ++i) {
		this->_inventory[i] = __nullptr;
	}
	this->_last_index = 0;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < INV_SIZE; ++i) {
		delete this->_inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria *m) {
	this->_inventory[_last_index] = m;
	_last_index++;
	_last_index %= INV_SIZE;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < INV_SIZE; ++i) {
		if (this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	return __nullptr;
}
