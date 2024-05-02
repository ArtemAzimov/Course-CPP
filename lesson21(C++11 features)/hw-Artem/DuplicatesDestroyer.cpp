#include "DuplicatesDestroyer.hpp"
#include "getHash.hpp"

constexpr size_t cVectorFileSize = 1;

DuplicateDestroyer::DuplicateDestroyer(){
    _path = fs::current_path().parent_path();   // Поправка чтобы тест проходил не в папке build
    std::cout << "****SELECTED PATH: " << _path << std::endl;
};
DuplicateDestroyer::DuplicateDestroyer(const std::string& userpath){
    if (userpath == "root"){
        _path = fs::current_path().root_path();
        std::cout << "****SELECTED PATH: " << _path << std::endl;
    }
    else {
        _path = userpath;
        std::cout << "****SELECTED PATH: " << _path << std::endl;
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
bool DuplicateDestroyer::checkKeyEntry(const size_t& hash){
    auto it = _duplicates.find(hash);
    if (it != _duplicates.end()){
        return true;
    }
    else {return false;}
}
// Для группировки по размеру файлов
bool DuplicateDestroyer::checkKeyEntrySize(const uintmax_t& size){
    auto it = _allFiles.find(size);
    if (it != _allFiles.end()){
        return true;
    }
    else {return false;}
}

// Поиск по path файла в векторе
bool DuplicateDestroyer::checkFileEntry(const fs::path& file){
    for (auto [hash, files] : _duplicates){
        if ((std::find(files.begin(), files.end(), file)) != files.end()){
            return true;
        }
    }
    return false;
}
// Для группировки по размеру файлов - поиск по path файла в векторе мапы
bool DuplicateDestroyer::checkFileEntrySize(const fs::path& file){
    for (auto [size, files] : _allFiles){
        if ((std::find(files.begin(), files.end(), file)) != files.end()){
            return true;
        }
    }
    return false;
}

// Создать в мапе ключ и запушить в вектор файл
void DuplicateDestroyer::createPair(size_t hash, fs::path file){        
    _duplicates[hash].push_back(file);
}
// Для группировки по размеру файлов
void DuplicateDestroyer::createPairSize(uintmax_t size, fs::path file){        
    _allFiles[size].push_back(file);
}

// Найти в мапе ключ и запушить в вектор файл
void DuplicateDestroyer::addFile(size_t hash, fs::path file){
    auto it = _duplicates.find(hash);
    (*it).second.push_back(file);
}
// Для группировки по размеру файлов
void DuplicateDestroyer::addFileSize(uintmax_t size, fs::path file){
    auto it =_allFiles.find(size);
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
            if(!checkKeyEntrySize(fileSize)){
                createPairSize(fileSize, filePath);
            }
            // Если в словаре есть такой размер файла, но нет этого файла - добавить файл по ключу размер файла
            if(checkKeyEntrySize(fileSize) && !checkFileEntrySize(filePath)){
                addFileSize(fileSize, filePath);
            }
        }
    }

    for (const auto [size, files] : _allFiles){
        for (const auto file : files){
            std::cout << size << " : " << file.filename() << '\n';
        }
    }
}

// *** FIXED BUG ***
// Фильтрует НЕдупликаты (удаляет ключи из мапы, где размер вектора <= 1)
void DuplicateDestroyer::filterNonDuplicates(){
    std::cout << "\n........called filterNonDuplicates\n";
    std::unordered_map<uintmax_t, std::vector<fs::path>> filteredVec;   // NB! Не изменять вектор в лупе
    for (auto [size, files] : _allFiles){
        if (files.size() != cVectorFileSize){
            filteredVec.insert({size, files});
        }
    }
    _allFiles = filteredVec;
    filteredVec.clear();

    for (const auto [size, files] : _allFiles){
        for (const auto file : files){
            std::cout << size << " : " << file.filename() << '\n';
        }
    }
}

void DuplicateDestroyer::getFileContent(){
    std::cout << "\n........called getFileContent\n";
    for (auto [size, files] : _allFiles){
        for (auto file : files){
            size_t hash = getHash(file);
            // Если в мапе нет хэша = создать ключ(хэш):значение(файл)
            if(!checkKeyEntry(hash)){
                createPair(hash, file);
            }
            // Если в мапе есть такой хэш, но нет файла с таким хэшем - добавить файл по ключу хэш
            if(checkKeyEntry(hash) && !checkFileEntry(file)){
                addFile(hash, file);
            }
        }
    }
}

void DuplicateDestroyer::print(){
    for (auto [hash, files] : _duplicates){
        std::cout << std::hex << std::uppercase << hash << " : ";
        for (auto file : files) {
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