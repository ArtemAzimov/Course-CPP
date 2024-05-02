#pragma once

#include <fstream>
#include <iostream>
#include <string>

class FileReader
{
	std::ifstream file;

public:
	FileReader(const std::string& filename);
	~FileReader();


	void operator >> (std::string& text)
	{
		std::getline(file, text);
	}
};

FileReader::FileReader(const std::string& filename)
{
	file.open(filename, std::ios_base::in);
}

FileReader::~FileReader()
{
	file.close();
}

