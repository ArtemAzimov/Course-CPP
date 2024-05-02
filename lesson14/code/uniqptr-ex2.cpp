#include <iostream>
#include <memory>
#include <fstream>

class FileReader {
public:
    FileReader(std::string filename) : m_file(filename, std::ios::in) {
        if (!m_file.is_open()) {
            throw std::runtime_error("Failed to open file.");
        }
    }

    std::string readLine() {
        std::string line;
        if (std::getline(m_file, line)) {
            return line;
        }
        return "";
    }

private:
    std::ifstream m_file;
};

int main() {
    try {
        std::unique_ptr<FileReader> reader(new FileReader("example.txt"));
        std::string line = reader->readLine();
        while (line != "") {
            std::cout << line << std::endl;
            line = reader->readLine();
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
