#include <iostream>
#include <string>

class Logger
{
private:
    std::string pass;
    size_t h2;
public:
    Logger(){h2 = std::hash<std::string>{}(pass);}

    bool log_in(std::string str)
    {
        size_t h1 = std::hash<std::string>{}(str);
        if (h1 == h2){return true;}
        else return false;
    }
};


int main()
{
    Logger ses1;
    std::string str;
    std::cout << "Enter password >: ";
    std::cin >> str;
    if (ses1.log_in(str)) {std::cout << "SUCCESS!" << std::endl;}
    else std::cout << "FAILED" << std::endl;

    return 0;
}