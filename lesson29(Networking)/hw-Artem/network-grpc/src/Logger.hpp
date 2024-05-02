#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <ctime>

// Паттерн Синглтон
class Logger{
private:
	Logger() = default;
	Logger(const Logger&) = delete;
	Logger& operator = (const Logger&) = delete;
	std::fstream logFile;
	char* timestamp;
public:
	~Logger();
	static Logger& self(){
		static Logger instance;
		return (instance);
	}

	std::string getTimeStamp();
	void createLogFile();
	void write(const std::string& message);
};

#endif // LOGGER_HPP