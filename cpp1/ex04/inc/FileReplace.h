//
// Created by mscheman on 8/19/24.
//

#ifndef FILEREPLACE_H
#define FILEREPLACE_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

#include "colors.h"

class FileReplace {
	private:
		std::ifstream	_infile;
		std::ofstream	_outfile;
		std::string		_buffer;
		std::string		_seek;
		std::string		_replace;
		void	readLine();
		void	modifyBuffer(unsigned long start_index = 0);
		void	writeLine();
	public:
		FileReplace(const std::string &path, const std::string &s1, const std::string &s2);
		~FileReplace();
		void	run();

};

#endif //FILEREPLACE_H
