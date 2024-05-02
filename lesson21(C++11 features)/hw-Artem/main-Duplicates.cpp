#include "DuplicatesDestroyer.hpp"
#include <chrono>

// Создает в ./ директорию "DuplicatesDestroyer", в которой также создает поддиректорию "subdir_example" и заполняет их файлами-дубликатами
void TEST_PREPARE(){
    std::string path = fs::current_path().parent_path().string();   // Поправка чтобы тест проходил не в папке build
    std::string test_path = path + R"(/DuplicatesDestroyer)";
    fs::create_directory(test_path);
    std::string subdir_path = test_path + R"(/subdir_example)";
    fs::create_directory(subdir_path); 
    
    std::string words = "Some words to test";

    for (int it = 1; it < 4; ++it){
        std::string filename = test_path + R"(/example)" + std::to_string(it) + ".txt";
        std::ofstream file(filename, std::ios::out);
        file << words;
        file.close();
    }

    for (int it = 4; it < 7; ++it){
        std::string filename = subdir_path + R"(/example)" + std::to_string(it) + ".txt";
        std::ofstream file(filename);
        file << words;
        file.close();
    }

    words = "ABSOLUTELY DIFFERENT WORDS FOR TESTING";
    for (int it = 1; it < 4; ++it){
        std::string filename = test_path + R"(/DIFFERENT_)" + std::to_string(it) + ".txt";
        std::ofstream file(filename, std::ios::out);
        file << words;
        file.close();
    }
}

void TEST_LOCAL_DIR_RUN(){
    DuplicateDestroyer obj1;
    obj1.getFileSize();
    obj1.filterNonDuplicates();
    obj1.getFileContent();
    obj1.print();
}

void TEST_SYSTEM_ROOT(){
    std::string path = "root";
    DuplicateDestroyer obj1(path);
    obj1.getFileSize();
    obj1.filterNonDuplicates();
    obj1.getFileContent();
    obj1.print();
}

int main(){
    TEST_PREPARE();
    TEST_LOCAL_DIR_RUN();
    // TEST_SYSTEM_ROOT();
    
    // Директивы препроцессора для консоли
    #if defined (_WIN32)
    system("pause");
    #else
    getchar();
    #endif

    return 0;
}