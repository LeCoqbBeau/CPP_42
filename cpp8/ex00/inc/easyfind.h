//
// Created by mscheman on 10/19/24.
//

#ifndef EASYFIND_H
#define EASYFIND_H

# include "utils.h"

# include <algorithm>
# include <iterator>
# include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(T cref container, int search);

template <typename T>
int easyfind(std::queue<T> cref container, int search);

template <typename T>
int easyfind(std::priority_queue<T> cref container, int search);

template <typename T>
int easyfind(std::stack<T> cref container, int search);

#include "easyfind.tpp"

#endif //EASYFIND_H
