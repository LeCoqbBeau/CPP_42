//
// Created by mscheman on 8/19/24.
//

#include "FileReplace.h"

FileReplace::FileReplace(const std::string &path, const std::string &s1, const std::string &s2) {
	this->_infile.open(path.c_str(), std::ios::in);
	if (!this->_infile)
		exit(error(1));
	this->_outfile.open(std::string(path + ".replace").c_str(), std::ios::out);
	if (!this->_outfile)
		exit(error(2));
	this->_seek = s1;
	this->_replace = s2;
}

FileReplace::~FileReplace() {
	if (this->_infile)
		this->_infile.close();
	if (this->_outfile)
		this->_outfile.close();
}

void FileReplace::readLine() {
	std::getline(_infile, _buffer);
	if (_buffer.empty())
		_buffer = "";
}

static std::string mult_str(const std::string &replace, unsigned long n);

void FileReplace::modifyBuffer(unsigned long start_index) {
	unsigned long	index;
	std::string		tmp;

	if (_seek.empty())
	{
		_buffer = mult_str(_replace, _buffer.length());
		return;
	}
	if (start_index >= _buffer.length())
		return;
	index = _buffer.find(_seek, start_index);
	if (index == std::string::npos)
		return;
	tmp = _buffer.substr(0, index);
	tmp += _replace;
	tmp += _buffer.substr(index + _seek.length());
	_buffer = tmp;
	modifyBuffer(index);
}

static std::string mult_str(const std::string &replace, unsigned long n) {
	std::string tmp;

	tmp = "";
	while (n > 0)
	{
		tmp += replace;
		n--;
	}
	return tmp;
}

void FileReplace::writeLine() {
	_outfile << _buffer;
	if (!_infile.eof())
		_outfile << std::endl;
}

void FileReplace::run() {
	while (!_infile.eof())
	{
		readLine();
		modifyBuffer();
		writeLine();
	}
}
