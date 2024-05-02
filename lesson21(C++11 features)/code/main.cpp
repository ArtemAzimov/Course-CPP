#include <iostream>

#ifdef _WIN32
std::string path = "C://Users"; 
#else
std::string path = "/home/Users"; 
#endif

int main(int, char**) {
    std::cout << "Path " << path << '\n';
}
