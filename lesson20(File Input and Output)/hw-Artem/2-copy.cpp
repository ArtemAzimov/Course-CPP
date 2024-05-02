#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

void copy(){
    std::ifstream infile("input.txt");
    if (!infile) {throw std::runtime_error("Unable to open input.txt");}
    std::ofstream outfile("output.txt", std::ios::app);
    if (!outfile) {throw std::runtime_error("Unable to open output.txt");}

    std::string s;
    while(std::getline(infile, s)){
        outfile << s;
    }
    std::cout << "COPY SUCCESS" << std::endl;

    infile.close();
    outfile.close();
}

int main(){
    try{
        copy();
    }
    catch(const std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}