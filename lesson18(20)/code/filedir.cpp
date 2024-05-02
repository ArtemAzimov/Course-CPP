#include <iostream>
#include <fstream>
#include <filesystem>

int main() {
    try {
        // Создание файла
        std::ofstream file("example.txt");
        if (!file) {
            throw std::runtime_error("Failed to create the file.");
        }
        file << "Hello, World!";
        file.close();
        std::cout << "File created successfully." << std::endl;

        // Переименование файла
        std::filesystem::rename("example.txt", "new_example.txt");
        std::cout << "File renamed successfully." << std::endl;

        // Удаление файла
        std::filesystem::remove("new_example.txt");
        std::cout << "File removed successfully." << std::endl;

        // Создание директории
        std::filesystem::create_directory("new_directory");
        std::cout << "Directory created successfully." << std::endl;

        // Переход в директорию
        std::filesystem::current_path("new_directory");
        std::cout << "Current directory: " << std::filesystem::current_path() << std::endl;

        // Удаление директории
        std::filesystem::remove("new_directory");
        std::cout << "Directory removed successfully." << std::endl;

        // Получение информации о файле
        std::filesystem::path filePath("file.txt");
        if (std::filesystem::exists(filePath)) {
            std::cout << "File exists." << std::endl;

            if (std::filesystem::is_regular_file(filePath)) {
                std::cout << "Regular file." << std::endl;
                std::cout << "File size: " << std::filesystem::file_size(filePath) << " bytes." << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
