//
// Created by mscheman on 8/16/24.
//

#include <deque>
#include <list>
#include <vector>
#include <queue>
#include <stack>

#include <ctime>
#include <cstdlib>

#include "easyfind.h"

#define MAX_VALUES 5
#define MAX_VALUE 100
#define TEMPLATE_T template <typename T>
#define TEMPLATE_N template <>

// Prototypes
static bool isNumberContained(const int *array, int cref elem, int size);
static void search(int *values, int search);
TEMPLATE_T static void randomize(T ref container, int *numbers);
TEMPLATE_T static void containerAdaptorRandomize(T ref container, int *numbers);
TEMPLATE_N void randomize(std::queue<int> ref container, int *numbers);
TEMPLATE_N void randomize(std::priority_queue<int> ref container, int *numbers);
TEMPLATE_N void randomize(std::stack<int> ref container, int *numbers);
TEMPLATE_T static void print(T ref container);
TEMPLATE_N void print(std::queue<int> ref container);
TEMPLATE_N void print(std::priority_queue<int> ref container);
TEMPLATE_N void print(std::stack<int> ref container);

// Implementations
int	main()
{
	int	values[MAX_VALUES];
	// Number Randomizer
	int	random;
	srand(time(NULL));
	for (int i = 0; i < MAX_VALUES; ++i) {
		random = std::rand() % MAX_VALUE;
		while (isNumberContained(values, random, MAX_VALUES))
			random = std::rand() % MAX_VALUE;
		values[i] = std::rand() % MAX_VALUE;
	}

	int chosen = values[std::rand() % MAX_VALUES];

	// Existing value
	search(values, chosen);

	while (isNumberContained(values, chosen, MAX_VALUES))
		chosen = std::rand() % MAX_VALUE;

	// Unexisting value
	search(values, chosen);
}

static void search(int *values, const int search) {
	str							value;
	std::deque<int>				deque;
	std::list<int>				list;
	std::vector<int>			vector;
	std::queue<int>				queue;
	std::priority_queue<int>	priority;
	std::stack<int>				stack;

	randomize(deque, values);
	randomize(list, values);
	randomize(vector, values);
	randomize(queue, values);
	randomize(priority, values);
	randomize(stack, values);

	NEWL;
	PRINT PRP BOLD "Now searching element: " CLR AND search ENDL;
	NEWL;
	value = "[NOT FOUND]";
	TRY(value = TOSTR(*easyfind(deque, search)))
	PRINT GRN BOLD "In deque: " CYN BOLD AND value ENDL;
	PRINT YLW BOLD "deque: " CLR;
	print(deque);
	NEWL;
	value = "[NOT FOUND]";
	TRY(value = TOSTR(*easyfind(list, search)))
	PRINT GRN BOLD "In list: " CYN BOLD AND value ENDL;
	PRINT YLW BOLD "list: " CLR;
	print(list);
	NEWL;
	value = "[NOT FOUND]";
	TRY(value = TOSTR(*easyfind(vector, search)))
	PRINT GRN BOLD "In vector: " CYN BOLD AND value ENDL;
	PRINT YLW BOLD "vector: " CLR;
	print(vector);
	NEWL;
	value = "[NOT FOUND]";
	TRY(value = TOSTR(easyfind(queue, search));)
	PRINT GRN BOLD "In queue: " CYN BOLD AND value ENDL;
	PRINT YLW BOLD "queue: " CLR;
	print(queue);
	NEWL;
	value = "[NOT FOUND]";
	TRY(value = TOSTR(easyfind(priority, search)))
	PRINT GRN BOLD "In priority_queue: " CYN BOLD AND value ENDL;
	PRINT YLW BOLD "priority_queue: " CLR;
	print(priority);
	NEWL;
	value = "[NOT FOUND]";
	TRY(value = TOSTR(easyfind(stack, search)))
	PRINT GRN BOLD "In stack: " CYN BOLD AND value ENDL;
	PRINT YLW BOLD "stack: " CLR;
	print(stack);
	NEWL;
}

static bool isNumberContained(const int *array, int cref elem, int size) {
	for (int i = 0; i < size; ++i) {
		if (array[i] == elem)
			return true;
	}
	return false;
}

// Randomizer
TEMPLATE_T void randomize(T ref container, int *numbers) {
	std::random_shuffle(&numbers[0], &numbers[MAX_VALUES]);
	for (int i = 0; i < MAX_VALUES; ++i) {
		container.push_back(numbers[i]);
	}
}

// Container Adaptor Randomizer
TEMPLATE_T void containerAdaptorRandomize(T ref container, int *numbers) {
	std::random_shuffle(&numbers[0], &numbers[MAX_VALUES]);
	for (int i = 0; i < MAX_VALUES; ++i) {
		container.push(numbers[i]);
	}
}

TEMPLATE_N void randomize(std::queue<int> ref container, int *numbers) {
	containerAdaptorRandomize(container, numbers);
}

TEMPLATE_N void randomize(std::priority_queue<int> ref container, int *numbers) {
	containerAdaptorRandomize(container, numbers);
}

TEMPLATE_N void randomize(std::stack<int> ref container, int *numbers) {
	containerAdaptorRandomize(container, numbers);
}

// Print
TEMPLATE_T void print(T ref container) {
	for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
		PRINT *it AND " ";
	}
}

TEMPLATE_N void print(std::queue<int> ref container) {
	while (!container.empty()) {
		PRINT container.front() AND " ";
		container.pop();
	}
}

TEMPLATE_N void print(std::priority_queue<int> ref container) {
	while (!container.empty()) {
		PRINT container.top() AND " ";
		container.pop();
	}
}

TEMPLATE_N void print(std::stack<int> ref container) {
	while (!container.empty()) {
		PRINT container.top() AND " ";
		container.pop();
	}
}
