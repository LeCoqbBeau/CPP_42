//
// Created by mscheman on 10/19/24.
//

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() : std::stack<T>() {};

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator				begin() const {
		return this->c.begin();
	}

	iterator				end() const {
		return this->c.end();
	}

	const_iterator			cbegin() const {
		return this->c.cbegin();
	}

	const_iterator			cend() const {
		return this->c.cend();
	}

	reverse_iterator		rbegin() const {
		return this->c.rbegin();
	}

	reverse_iterator		rend() const {
		return this->c.rend();
	}

	const_reverse_iterator	crbegin() const {
		return this->c.rbegin();
	}

	const_reverse_iterator	crend() const {
		return this->c.rend();
	}

};

#endif //MUTANTSTACK_H
