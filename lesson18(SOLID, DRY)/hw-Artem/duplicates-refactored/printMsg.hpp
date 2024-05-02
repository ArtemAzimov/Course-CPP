#include <iostream>
#include <string>
#include <stdexcept>

class PrintMsg{
public:
    std::string str;
    void welcome(){
        std::string str = R"(---* PATH FORMAT: C:\dir\dir)";
        str += '\n';
        str += R"(---* OR HIT "ENTER" KEY TO USE CURRENT DIRECTORY)";
        str += '\n';
        str += "Enter your path >: ";
        std::cout << str;
    }

    void path(std::filesystem::path& path){
        std::cout << "Path: " << path << " selected \n"; 
    }

    void help(){
        str = "List of commands:";
        str += '\n';
        str += "help \t start \t exit \n";
        std::cout << str;
    }

    void start(){
        str = R"(START SCAN FOR DUPLICATE FILES? "Y/N" >: )";
        std::cout << str;
    }

    void exit(){
        str = "STOPPING PROGRAM BY USER...";
        std::cout << str;
    }

    void scan(){
        str = "---* SCANNING FOR DUPLICATED FILES... \n";
        std::cout << str;
    }
};
