
# include "easyfind.h"

template <typename T>
typename T::const_iterator easyfind(T cref container, int search) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), search);
	if (it != container.end())
		return (it);
	throw std::logic_error("Searched element (" + TOSTR(search) + ") not found");
}

template <typename T>
int easyfind(std::queue<T> cref container, int search) {
	std::queue<T> loop = container;
	while (!loop.empty()) {
		if (loop.front() == search)
			return (loop.front());
		loop.pop();
	}
	throw std::logic_error("Searched element (" + TOSTR(search) + ") not found");
}

template <typename T>
int easyfind(std::priority_queue<T> cref container, int search) {
	std::priority_queue<T> loop = container;
	while (!loop.empty()) {
		if (loop.top() == search)
			return (loop.top());
		loop.pop();
	}
	throw std::logic_error("Searched element (" + TOSTR(search) + ") not found");
}

template <typename T>
int easyfind(std::stack<T> cref container, int search) {
	std::stack<T> loop = container;
	while (!loop.empty()) {
		if (loop.top() == search)
			return (loop.top());
		loop.pop();
	}
	throw std::logic_error("Searched element (" + TOSTR(search) + ") not found");
}
