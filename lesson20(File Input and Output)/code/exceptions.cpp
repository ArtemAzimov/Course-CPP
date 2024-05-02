#include <iostream>
#include <fstream>
#include <stdexcept>

class TError{
    public:
    TError(const char* message) {}
};

int main() {
    try {
        std::ifstream inputFile("nonexistent_file.txt");
        if (!inputFile) {
            // throw std::runtime_error("Failed to open the file.");
            throw TError("Failed to open the file.");
        }

        // Чтение данных из файла...

        inputFile.close();
    } catch (const TError& e) {
        std::cerr << "My Error: " << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Error " << std::endl;
    }

    return 0;
}