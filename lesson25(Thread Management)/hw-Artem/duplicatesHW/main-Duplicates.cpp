#include "DuplicatesDestroyer.hpp"

using namespace Duplicates_namespace;

// Создает в ./../ директорию "DuplicatesDestroyer", в которой также создает поддиректорию "subdir_example" и заполняет их файлами-дубликатами
void TEST_PREPARE(){
    // Поправка чтобы тест проходил не в папке build, делает ./../ - переход в родительскую директорию
    std::string path = fs::current_path().parent_path().string();
    std::string test_path = path + R"(/DuplicatesDestroyer)";
    fs::create_directory(test_path);
    std::string subdir_path = test_path + R"(/subdir_example)";
    fs::create_directory(subdir_path); 
    
    // Содержание дубликатов (тип А)
    std::string words = "Some words to test";

    // Создает 3 файла дубликатов (тип А) в папке ./../DuplicatesDestroyer
    for (int it = 1; it < 4; ++it){
        std::string filename = test_path + R"(/example)" + std::to_string(it) + ".txt";
        std::ofstream file(filename, std::ios::out);
        file << words;
        file.close();
    }

    // Создает 3 файла дубликатов (тип А) в папке ./../DuplicatesDestroyer/subdir_example
    for (int it = 4; it < 7; ++it){
        std::string filename = subdir_path + R"(/example)" + std::to_string(it) + ".txt";
        std::ofstream file(filename);
        file << words;
        file.close();
    }

    // Переопределение содержания дубликатов (тип Б)
    words = "ABSOLUTELY DIFFERENT WORDS FOR TESTING";
    // Создает 3 файла дубликатов (тип Б) в папке ./../DuplicatesDestroyer
    for (int it = 1; it < 4; ++it){
        std::string filename = test_path + R"(/DIFFERENT_)" + std::to_string(it) + ".txt";
        std::ofstream file(filename, std::ios::out);
        file << words;
        file.close();
    }
}

void TEST_LOCAL_DIR_RUN(){
    Duplicates_namespace::DuplicateDestroyer obj1;
    obj1.getFileSize();
    obj1.filterNonDuplicates();
    obj1.getFileContent();
}

void TEST_SYSTEM_ROOT(){
    std::string path = "root";
    Duplicates_namespace::DuplicateDestroyer obj1(path);
    obj1.getFileSize();
    obj1.filterNonDuplicates();
    obj1.getFileContent();
}

int main(){
    try
    {
        TEST_PREPARE();
        TEST_LOCAL_DIR_RUN();
        // TEST_SYSTEM_ROOT();
        
        // Директивы препроцессора для консоли
        /*
            Нашел вариант для запуска не в терминале IDE, а во внешнем (OS),
            но нужно пушить настройки launch.json, который в .gitignore:
              "cmake.debugConfig": {
                "externalConsole": true
                }
        */
        // #if defined (_WIN32)
        // system("pause");
        // #else
        // getchar();
        // #endif
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}