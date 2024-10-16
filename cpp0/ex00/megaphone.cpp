#include <iostream>
#include <cctype>
#include <string>

int	main(int argc, char *argv[])
{
	std::string				sentence;
	std::string::iterator	it;

	sentence = "* loud and unbearable feedback noise *";
	if (argc != 1)
		sentence = "";
	for (int i = 1; argv[i]; ++i)
		sentence += argv[i];
	for (it = sentence.begin(); it != sentence.end(); it++) {
		*it = toupper(*it);
	}
	std::cout << sentence << std::endl;
	return 0;
}

