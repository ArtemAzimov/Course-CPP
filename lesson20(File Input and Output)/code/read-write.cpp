#include <fstream>
#include <iostream>

int main(){
    std::ifstream stream("input.txt", std::ios::binary);
    stream.seekg(10);

    std::ofstream fout("output.txt");

    if (stream.is_open()){
        char ch = ' ';
        while(stream.get(ch)){
            std::streampos pos = stream.tellg();
            std::cout << pos << std::endl;
            fout.put(ch);
            fout.put(' ');
        }
        // char buffer[10] = {0};
        // while(stream.read(buffer, sizeof(buffer))){
        //     std::cout << buffer << '\n';
        // }
    } else {
        std::cerr << "Error opening input.txt" << std::endl;
    }

}