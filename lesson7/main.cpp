#include <iostream>
#include <string>
#include "ProgrammerCard.hpp"
#include <fstream>

using std::cout;
using std::endl;
using std::string;

int main()
{
    AbsCard* linus = new ProgrammerCard(1, "Linus Torvalds", 30000, 145, "C++");
    cout << linus->getInfo() << endl;
    
    std::ifstream f("file.txt");
    if (f.is_open())
        std::cout << f.rdbuf();
}

// g++ main.cpp ProgrammerCard.cpp -I . (указывает ключ директории) -o out
// g++ main.cpp ProgrammerCard.cpp -o out