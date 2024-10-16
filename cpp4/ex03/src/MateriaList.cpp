//
// Created by mscheman on 8/26/24.
//

#include "MateriaList.h"

Node::Node(AMateria *materia) {
	this->_materia = materia;
	this->_next = __nullptr;
}

Node::~Node() {}

AMateria *Node::getMateria() const {
	return _materia;
}

void Node::setMateria(AMateria *materia) {
	_materia = materia;
}

Node *Node::getNext() const {
	return _next;
}

void Node::setNext(Node *next) {
	Node::_next = next;
}

MateriaList::MateriaList() {
	this->_head = __nullptr;
}

MateriaList::~MateriaList() {
	while (this->_head != __nullptr)
		this->pop();
}

void MateriaList::append(AMateria *materia) {
	Node	*newNode = new Node(materia);
	if (this->_head == __nullptr)
	{
		this->_head = newNode;
		return;
	}
	Node	*temp = this->_head;
	while (temp->getNext() != __nullptr)
	{
		if (temp->getMateria() == materia)
		{
			delete newNode;
			return;
		}
		temp = temp->getNext();
	}
	if (temp->getMateria() == materia)
	{
		delete newNode;
		return;
	}
	temp->setNext(newNode);
}

void MateriaList::pop() {
	if (this->_head == __nullptr)
		return;
	if (this->_head->getNext() == __nullptr)
	{
		delete this->_head->getMateria();
		delete this->_head;
		this->_head = __nullptr;
		return;
	}
	Node	*temp = this->_head;
	while (temp->getNext()->getNext() != __nullptr)
		temp = temp->getNext();
	delete temp->getNext()->getMateria();
	delete temp->getNext();
	temp->setNext(__nullptr);
}

void MateriaList::print() {
	Node	*temp = this->_head;

	while (temp != __nullptr)
	{
		std::cout << temp->getMateria()->getType() << BBLK " [ " << temp->getMateria() << " ]" CLR " -> ";
		temp = temp->getNext();
	}
	std::cout << std::endl;
}
