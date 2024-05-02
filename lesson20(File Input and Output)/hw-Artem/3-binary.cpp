#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

struct Student{
    int id;
    std::string name;
    int age;
    int score;
};

void binary(){
    std::ifstream file("students.bin", std::ios::binary);
    file.seekg(20, std::ios::beg);          // пропустить строки и \n в начале файла и начать с 20 байта

    std::string s;
    while(std::getline(file, s)){       // нужен разделитель для структур
        std::cout << s << std::endl;
    }
}

int main(){
    binary();

    return 0;
}
