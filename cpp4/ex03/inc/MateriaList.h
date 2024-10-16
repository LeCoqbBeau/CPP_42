//
// Created by mscheman on 8/26/24.
//

#ifndef EX03_MATERIALIST_H
#define EX03_MATERIALIST_H

#include "AMateria.h"

class Node {
	private:
			AMateria	*_materia;
			Node		*_next;
	public:
		Node(AMateria *materia);
		~Node();

	AMateria *getMateria() const;
	void setMateria(AMateria *materia);
	Node *getNext() const;
	void setNext(Node *next);
};

class MateriaList {
	private:
		Node	*_head;
	public:
		MateriaList();
		~MateriaList();
		void append(AMateria *materia);
		void pop();
		void print();
};


#endif //EX03_MATERIALIST_H
