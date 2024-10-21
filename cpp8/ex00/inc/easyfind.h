//
// Created by mscheman on 10/19/24.
//

#ifndef EASYFIND_H
#define EASYFIND_H

# include <algorithm>
# include <iterator>

template <typename T>
typename T::const_iterator easyfind(const T &container, int search);

template <typename T>
int easyfind(const std::queue<T> &container, int search);

template <typename T>
int easyfind(const std::stack<T> &container, int search);

template <typename T>
typename std::map<int, T>::const_iterator easyfind(const std::map<int, T> &map, int search);

#include "easyfind.tpp"

#endif //EASYFIND_H
