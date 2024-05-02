#pragma once

#include <iostream>
#include <fstream>
#include <string>

class FileWriter
{
	std::ofstream file;

public:
	FileWriter(const std::string& filename);
	~FileWriter();

	bool operator << (const std::string& text);
};

FileWriter::FileWriter(const std::string& filename)
{
	file.open(filename, std::ios_base::out | std::ios_base::app);
	// 0010
	// 0100
	// 0110
	// std::ios_base - содержит флаги
}

FileWriter::~FileWriter()
{
	file.close();
}

// ? **************************************************

bool FileWriter::operator << (const std::string& text)
{
	if (file.is_open())
	{
		file << text;
		return true;
	}
	else
		std::cerr << "Error: bad descriptor" << std::endl;
	return false;
}