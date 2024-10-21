//
// Created by mscheman on 8/16/24.
//

#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include <ctime>
#include <cstdlib>

#include "easyfind.h"

#include <iostream>
#include "colors.h"
#include "printUtils.h"

#define MAX_VALUES 5

static bool isNumberContained(const int *array, const int &elem, int size);

template <typename T>
void	randomize(T &container, int *numbers);

void	randomize(std::queue<int> &container, int *numbers);
void	randomize(std::stack<int> &container, int *numbers);
void	randomize(std::set<int> &container, int *numbers);
void	randomize(std::map<int, int> &map, int *numbers);

template <typename T>
void	print(T &container);
void	print(std::queue<int> queue);
void	print(std::stack<int> stack);
template <typename T>
void	print(std::map<int, T> &map);

static void search(int *values, int search);

int	main()
{
	int	values[MAX_VALUES];
	// Number Randomizer
	int	random;
	srand(time(NULL));
	for (int i = 0; i < MAX_VALUES; ++i) {
		random = rand();
		while (isNumberContained(values, random, MAX_VALUES))
			random = rand();
		values[i] = rand();
	}

	int chosen = values[rand() % MAX_VALUES];

	// Existing value
	search(values, chosen);

	while (isNumberContained(values, chosen, MAX_VALUES))
		chosen = rand();

	// Unexisting value
	search(values, chosen);
}

static void search(int *values, int search) {
	std::deque<int>		deque;
	std::list<int>		list;
	std::map<int, int>	map;
	std::queue<int>		queue;
	std::set<int>		set;
	std::stack<int>		stack;
	std::vector<int>	vector;

	randomize(deque, values);
	randomize(list, values);
	randomize(map, values);
	randomize(queue, values);
	randomize(set, values);
	randomize(stack, values);
	randomize(vector, values);

	NEWL;
	PRINT BPRP "Now searching element: " CLR AND search ENDL;

	PRINT BGRN "In deque: " BCYN AND *easyfind(deque, search) ENDL;
	PRINT BYLW "deque: " CLR;
	print(deque);
	NEWL;
	PRINT BGRN "In list: " BCYN AND *easyfind(list, search) ENDL;
	PRINT BYLW "list: " CLR;
	print(list);
	NEWL;
	PRINT BGRN "In map: " BCYN AND easyfind<int>(map, search)->first AND BBLK " ( " AND easyfind<int>(map, search)->second AND " )" ENDL;
	PRINT BYLW "map: " CLR;
	print(map);
	NEWL;
	PRINT BGRN "In queue: " BCYN AND easyfind(queue, search) ENDL;
	PRINT BYLW "queue: " CLR;
	print(queue);
	NEWL;
	PRINT BGRN "In set: " BCYN AND *easyfind(set, search) ENDL;
	PRINT BYLW "set: " CLR;
	print(set);
	NEWL;
	PRINT BGRN "In stack: " BCYN AND easyfind(stack, search) ENDL;
	PRINT BYLW "stack: " CLR;
	print(stack);
	NEWL;
	PRINT BGRN "In vector: " BCYN AND *easyfind(vector, search) ENDL;
	PRINT BYLW "vector: " CLR;
	print(vector);
	NEWL;
}

static bool isNumberContained(const int *array, const int &elem, int size) {
	for (int i = 0; i < size; ++i) {
		if (array[i] == elem)
			return true;
	}
	return false;
}

// Randomizer
template <typename T>
void	randomize(T &container, int *numbers) {
	std::random_shuffle(&numbers[0], &numbers[MAX_VALUES]);
	for (int i = 0; i < MAX_VALUES; ++i) {
		container.push_back(numbers[i]);
	}
}

// Queue Randomizer
void	randomize(std::queue<int> &container, int *numbers) {
	std::random_shuffle(&numbers[0], &numbers[MAX_VALUES]);
	for (int i = 0; i < MAX_VALUES; ++i) {
		container.push(numbers[i]);
	}
}

// Stack Randomizer
void	randomize(std::stack<int> &container, int *numbers) {
	std::random_shuffle(&numbers[0], &numbers[MAX_VALUES]);
	for (int i = 0; i < MAX_VALUES; ++i) {
		container.push(numbers[i]);
	}
}

// Set Randomizer
void	randomize(std::set<int> &container, int *numbers) {
	std::random_shuffle(&numbers[0], &numbers[MAX_VALUES]);
	for (int i = 0; i < MAX_VALUES; ++i) {
		container.insert(numbers[i]);
	}
}

// Map Randomizer
void	randomize(std::map<int, int> &map, int *numbers) {
	std::random_shuffle(&numbers[0], &numbers[MAX_VALUES]);
	std::map<int, int>::iterator it = map.begin();
	for (int i = 0; i < MAX_VALUES; ++i) {
		map.insert(it, std::pair<int, int>(numbers[i], i));
	}
}

// Print
template <typename T>
void	print(T &container) {
	for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
		PRINT *it AND " ";
	}
}

// Queue printer
void	print(std::queue<int> queue) {
	while (!queue.empty()) {
		PRINT queue.front() AND " ";
		queue.pop();
	}
}

// Stack printer
void	print(std::stack<int> stack) {
	while (!stack.empty()) {
		PRINT stack.top() AND " ";
		stack.pop();
	}
}

// Map printer
template <typename T>
void	print(std::map<int, T> &map) {
	for (typename std::map<int, T>::const_iterator it = map.begin(); it != map.end(); ++it) {
		PRINT it->first AND BBLK " ( " AND it->second AND " ) " CLR;
	}
}