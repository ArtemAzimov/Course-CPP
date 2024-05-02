#include "Logger.hpp"

Logger::~Logger(){
	logFile.close();
};

std::string Logger::getTimeStamp(){
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
	std::string str(buffer);
	return str;
}

void Logger::createLogFile(){
	logFile.open("../../log.txt");
	std::cout << "Checking if log.txt exists..." << std::endl;
    if (logFile.is_open()){
		std::cout << "log.txt is found" << std::endl;
		logFile.close();
		logFile.open("../../log.txt", std::ios::out | std::ios::app);
	}
    else {
		std::fstream logFile("../../log.txt", std::ios::out | std::ios::app); 
		std::cout << "log.txt not found and was created " << std::endl;
	}
}

void Logger::write(const std::string& message) {
	if (logFile.is_open()){
		logFile << getTimeStamp() << "   " << message << '\n';
	}
	else{
		logFile.open("../../log.txt", std::ios::out | std::ios::app);
		logFile << getTimeStamp() << "   " << message << '\n';
	}
}