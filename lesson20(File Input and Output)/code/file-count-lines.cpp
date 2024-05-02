#include <iostream>
#include <fstream>
#include <string>

int countLines(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open the file.");
    }

    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        ++count;
    }

    file.close();
    return count;
}

int main() {
    try {
        std::string filename = "textfile.txt";
        int lineCount = countLines(filename);
        std::cout << "Number of lines: " << lineCount << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
