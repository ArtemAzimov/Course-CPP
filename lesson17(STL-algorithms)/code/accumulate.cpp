#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

int main(int argc, char **argv){
    std::vector<std::string> vStr{"Hello", " ", "from", " ", "C++"};
    std::string str = std::accumulate(vStr.begin(), vStr.end(), std::string(), [](auto a, auto b){return a+b;});


    std::string str2;
    for (auto it: vStr){
        str2 += it;
    }

    std::cout << str << std::endl;
    std::cout << str2 << std::endl;

}