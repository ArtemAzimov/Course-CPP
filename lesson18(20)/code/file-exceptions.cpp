#include <iostream>
#include <fstream>
#include <stdexcept>

void readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open the file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
}

void writeFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to create or open the file.");
    }

    file << content;

    file.close();
}

int main() {
    try {
        std::string filename = "example.txt";

        // Чтение файла
        std::cout << "Reading file..." << std::endl;
        readFile(filename);

        // Запись файла
        std::string content = "Hello, World!";
        std::cout << "Writing file..." << std::endl;
        writeFile(filename, content);

        // Повторное чтение файла
        std::cout << "Reading file again..." << std::endl;
        readFile(filename);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
