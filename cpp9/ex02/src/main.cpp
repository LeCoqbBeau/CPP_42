//
// Created by mscheman on 8/16/24.
//

#include "PmergeMe.h"

static void fillSorter(PmergeMe ref sorter, str cref sequence);

int	main(int argc, char *argv[]) {
	PmergeMe sorter;
	if (argc == 1) {
		ERROR RED BOLD "Wrong input" CENDL;
		ERROR BOLD "Usage: " AND argv[0] AND " '<sequence of uint>'" CENDL;
	}
	str sequence;
	for (int i = 1; i < argc; ++i)
		sequence.append(argv[i]).append(1, ' ');
	TRY_RETURN(fillSorter(sorter, sequence));
	TRY_RETURN(sorter.sort(sorter.getVector()));
	TRY_RETURN(sorter.sort(sorter.getDeque()));
}

static void fillSorter(PmergeMe ref sorter, str cref sequence) {
	str arg;
	std::istringstream stream(sequence);
	while (stream >> arg) {
		errno = 0;
		const uint num = std::strtol(arg.c_str(), __nullptr, 10);
		if (errno
			|| arg.find_first_not_of("0123456789+") != str::npos)
			throw std::invalid_argument("Invalid argument (" + arg + ")");
		sorter.push(num);
	}
}