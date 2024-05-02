#include "DuplicatesDestroyer.hpp"
#include "getHash.hpp"

using namespace Duplicates_namespace;
constexpr size_t cVectorFileSize = 1;

DuplicateDestroyer::DuplicateDestroyer(){
    _path = fs::current_path().parent_path();   // Поправка чтобы тест проходил не в папке build
    std::cout << "*** SELECTED PATH: " << _path << std::endl;
};
DuplicateDestroyer::DuplicateDestroyer(const std::string& userpath){
    if (userpath == "root"){
        _path = fs::current_path().root_path();
        std::cout << "*** SELECTED PATH: " << _path << std::endl;
    }
    else {
        _path = userpath;
        std::cout << "*** SELECTED PATH: " << _path << std::endl;
    }
};

/* PRIVATE*/
// Исключить папки .vscode и build из сканирования
bool DuplicateDestroyer::ignoredFolders(const fs::path& path){
    if (path.string().find(".vscode") != std::string::npos || path.string().find("build") != std::string::npos){
        return true;
    }
    else {return false;}
}

// Поиск по ключам в словаре. Проверка есть ли уже такой хэш
template <typename K>
bool DuplicateDestroyer::checkKeyEntry(const std::unordered_map<K, std::vector<fs::path>>& map, const K& key){
    auto it = map.find(key);
    if (it != map.end()){
        return true;
    }
    else {return false;}
}

// Поиск по path файла в векторе
template <typename K>
bool DuplicateDestroyer::checkFileEntry(const std::unordered_map<K, std::vector<fs::path>>& map, const fs::path& file){
    for (const auto& [hash, files] : map){
        if ((std::find(files.begin(), files.end(), file)) != files.end()){
            return true;
        }
    }
    return false;
}

// Создать в мапе ключ и запушить в вектор файл
template <typename K>
void DuplicateDestroyer::createPair(std::unordered_map<K, std::vector<fs::path>>& map, const K key, const fs::path file){        
    map[key].push_back(file);
}

// Найти в мапе ключ и запушить в вектор файл
template <typename K>
void DuplicateDestroyer::addFile(std::unordered_map<K, std::vector<fs::path>>& map, const K key, const fs::path file){
    auto it = map.find(key);
    (*it).second.push_back(file);
}

/* PUBLIC */
void DuplicateDestroyer::getFileSize(){
    std::cout << "\n........called getFileSize\n";
    for (fs::directory_entry filePath : fs::recursive_directory_iterator(_path/*, fs::directory_options::skip_permission_denied*/)){
        if (fs::is_regular_file(fs::path(filePath)) && !ignoredFolders(fs::path(filePath))){
            uintmax_t fileSize = fs::file_size(filePath);
            // std::cout << fileSize << " : " << fs::path(filePath).filename().string() << '\n';
            // Если в мапе нет размера файла = создать ключ(размер файла):значение(файл)
            if(!checkKeyEntry(_allFiles, fileSize)){
                createPair(_allFiles, fileSize, filePath);
            }
            // Если в словаре есть такой размер файла, но нет этого файла - добавить файл по ключу размер файла
            if(checkKeyEntry(_allFiles, fileSize) && !checkFileEntry(_allFiles, filePath)){
                addFile(_allFiles, fileSize, filePath);
            }
        }
    }

    print(_allFiles);
}

// *** FIXED BUG ***
// Фильтрует НЕдупликаты (удаляет ключи из мапы, где размер вектора <= 1)
void DuplicateDestroyer::filterNonDuplicates(){
    std::cout << "\n........called filterNonDuplicates\n";
    // NB! Не изменять вектор в лупе. Создает временный вектор, куда записывает измененные данные
    std::unordered_map<uintmax_t, std::vector<fs::path>> filteredVec;
    for (const auto [size, files] : _allFiles){
        if (files.size() != cVectorFileSize){
            filteredVec.insert({size, files});
        }
    }
    _allFiles = filteredVec;
    filteredVec.clear();

    print(_allFiles);
}

void DuplicateDestroyer::getFileContent(){
    std::cout << "\n........called getFileContent\n";
    for (auto [size, files] : _allFiles){
        for (auto file : files){
            size_t hash = getHash(file);
            // Если в мапе нет хэша = создать ключ(хэш):значение(файл)
            if(!checkKeyEntry(_duplicates, hash)){
                createPair(_duplicates, hash, file);
            }
            // Если в мапе есть такой хэш, но нет файла с таким хэшем - добавить файл по ключу хэш
            if(checkKeyEntry(_duplicates, hash) && !checkFileEntry(_duplicates, file)){
                addFile(_duplicates, hash, file);
            }
        }
    }
    print(_duplicates);
}

/*
    Темплейт для приема обеих мап - c ключами типа size_t(хэш файла) и uintmax_t(размер файла).
    size_t (в данном случае unsigned int) - 4 байта
    uintmax_t - 8 байта на WIN64 (stdint.h строка 152-154):
        <...>
        #ifndef SIZE_MAX
        #ifdef _WIN64
        #define SIZE_MAX UINT64_MAX
        <...>
*/
template <typename K>
void DuplicateDestroyer::print(const std::unordered_map<K, std::vector<fs::path>>& _primaryVector){
    for (const auto& [key, vector] : _primaryVector){
        std::cout << key << " : ";
        for (const auto& file : vector) {
            std::string shortFile = file.filename().string();
            std::cout << shortFile << ',' << "   ";
        }
        std::cout << std::endl;
    }
}

// void DuplicateDestroyer::deleteDuplicates(){
//     for (auto& [hash, files] : _duplicates){
//         auto it = files.begin() + 1;
//         for (auto& file : files){
//             fs::remove(*it);
//             // files.erase(it);
//         }
//     }
//     std::cout << std::endl << "DELETING DUPLICATES...\n" << std::endl;
// }