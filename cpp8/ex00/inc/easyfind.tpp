
# include "easyfind.h"

template <typename T>
typename T::const_iterator easyfind(const T &container, int search) {
	return std::find(container.begin(), container.end(), search);
}

template <typename T>
int easyfind(const std::queue<T> &container, int search) {
	std::queue<T> queue = container;
	while (!queue.empty()) {
		if (queue.front() == search)
			return queue.front();
		queue.pop();
	}
	return (0);
}

template <typename T>
int easyfind(const std::stack<T> &container, int search) {
	std::stack<T> stack = container;
	while (!stack.empty()) {
		if (stack.top() == search)
			return stack.top();
		stack.pop();
	}
	return (0);
}

template <typename T>
typename std::map<int, T>::const_iterator easyfind(const std::map<int, T> &map, int search) {
	return map.find(search);
}