#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <filesystem>
#include <algorithm>
#include "getHash.hpp"

namespace fs = std::filesystem;

/*
- разделение private, public
- hpp & cpp
- unordered map
- добавить проверку на size (сортировка - поиск элемент:элемент -> в новый вектор. Затем проход №2)
- unit тесты
- замерить время по скану из корня винды
*/

class HashFiles{
private:    
    // Словарь, содержащий пару Хэш:Вектор файлов
    std::unordered_map<size_t, std::vector<fs::path>> duplicates;
    fs::path _path;

public:
    HashFiles(){
        _path = fs::current_path();
    };
    HashFiles(const std::string& userpath){
        _path = userpath;
    };

    // void getFileSize(){

    // }

    void getFiles(){
        for (fs::directory_entry file : fs::recursive_directory_iterator(_path)){
            if (fs::is_regular_file(fs::path(file))){
                size_t hash = getHash(file);
                // Если в словаре нет хэша и нет файла = создать ключ(хэш):значение(файл)
                if(!checkKeyEntry(hash) && !checkFileEntry(file)){
                    createPair(hash, file);
                }
                // Если в словаре есть такой хэш, но нет этого файла - добавить файл по ключу хэш
                else if(checkKeyEntry(hash) && !checkFileEntry(file)){
                    addFile(hash, file);
                }
                else continue;
            }
        }
    }

    // Поиск по ключам в словаре. Проверка есть ли уже такой хэш
    bool checkKeyEntry(const size_t hash){
        auto it = duplicates.find(hash);
        if (it != duplicates.end()){
            return true;
        }
        else {return false;}
    }

    // Поиск по path файла в векторе
    bool checkFileEntry(const fs::path file){
        for (auto [hash, files] : duplicates){
            if ((std::find(files.begin(), files.end(), file)) != files.end()){
                return true;
            }
        }
        return false;
    }

    // Создать в мапе ключ и запушить в вектор файл
    void createPair(const size_t hash, const fs::path file){        
        duplicates[hash].push_back(file);
    }
    
    // Найти в мапе ключ и запушить в вектор файл
    void addFile(const size_t hash, const fs::path file){
        auto it = duplicates.find(hash);
        (*it).second.push_back(file);
    }

    void print(){
        for (auto [hash, files] : duplicates){
            std::cout << std::hex << std::uppercase << hash << " : ";
            for (auto& file : files) {
                std::string shortFile = file.filename().string();
                std::cout << shortFile << ',' << "   ";
            }
            std::cout << std::endl;
        }
    }

    void deleteDuplicates(){
        for (auto& [hash, files] : duplicates){
            // Если вектор файлов с одинаковым хэшем содержит > 1 элемента
            if (files.size() > 1){
                // Не учитывать оригинал
                files.erase(files.begin());
                // Удалить файлы
                for (auto& file : files){
                    fs::remove(file);
                }
            }
        }
        std::cout << std::endl << "DELETING DUPLICATES...\n" << std::endl;
    }
};

void testPrepare(std::string path){
    fs::create_directory(path + "subdir_example");
    std::string subdir_path = path + "subdir_example";
    std::string words = "Some words to test";

    for (int it = 4; it < 7; ++it){
        std::string filename = "example" + std::to_string(it) + ".txt";
        std::ofstream file(subdir_path + "/" + filename);
        file << words;
        file.close();
    }

    for (int it = 1; it < 4; ++it){
        std::string filename = path + "example" + std::to_string(it) + ".txt";
        std::ofstream file(filename, std::ios::out);
        file << words;
        file.close();
    }
}

bool testPath(){
    return true;
}

int main(){
    std::string path = R"(C:\mainnote\_PROG\cpp-beginner\lesson19(Move semantic)\hw-Artem\DuplicatesDestroyer\)";
    testPrepare(path);

    HashFiles hf(path);
    hf.getFiles();
    hf.print();
    hf.deleteDuplicates();

    HashFiles hf2(path);
    hf2.getFiles();
    hf2.print();

    return 0;
}