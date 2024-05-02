#include "Logger.hpp"

void Logger::warning(const std::string& message) {
	std::cerr << "WARNING: " << message << std::endl;
}

void Logger::error(const std::string& message) {
	std::cerr << "ERROR: " << message << std::endl;
	std::exit(1);
}
