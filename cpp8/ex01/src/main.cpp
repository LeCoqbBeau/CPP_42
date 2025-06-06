//
// Created by mscheman on 8/16/24.
//

#include <Span.h>

#define SPAN_SIZE 10
#define SPAN_SIZE_HALF (SPAN_SIZE / 2)

#include <bits/stdc++.h>
static bool isSorted(Span::container cref container);

int	main() {
	std::srand(std::time(__nullptr));
	// {
	// 	Span	small(SPAN_SIZE);
	//
	// 	for (int i = 0; i < SPAN_SIZE_HALF; ++i) {
	// 		small.addNumber(1 + i);
	// 	}
	//
	// 	Span::const_iterator start = small.getList().begin();
	// 	Span::const_iterator finish = small.getList().end();
	//
	// 	small.addNumber(start, finish);
	//
	// 	NEWL;
	// 	small.print();
	// 	NEWL;
	//
	// 	PRINT CYN BOLD "Shortest small's span: " CLR AND small.shortestSpan() ENDL;
	// 	PRINT CYN BOLD "Longest small's span: " CLR AND small.longestSpan() ENDL;
	// }
	// sleep(3);
	// NEWL;
	{
		Span	huge(1e5);

		huge.fillMemory();

		NEWL;
		huge.print();
		NEWL;

		PRINT CYN BOLD "Shortest small's span: " CLR AND huge.shortestSpan() ENDL;
		PRINT CYN BOLD "Longest huge's span: " CLR AND huge.longestSpan() ENDL;

		SHOW(isSorted(huge.getList())); // This proves that my method works
	}
}

bool isSorted(Span::container cref container) {
	const Span::const_iterator it = std::adjacent_find(
		container.begin(),
		container.end(),
		std::greater<int>()
	);
	if (it == container.end())
		return (true);
	return (false);
}