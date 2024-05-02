#include <iostream>
#include <fstream>
#include <stdexcept>

int countWords(){
    std::ifstream file ("input.txt");
    if (!file){
        throw std::runtime_error("Failed to open");
    }

    int count = 0;
    char c;
    while (file.get(c)){
        if (c == ' ' || c == '\n'){
            ++count;
        }
    }
    file.close();

    return count;
}

int main(){
    try{
        std::cout << countWords() << std::endl;
    }
    catch(const std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}