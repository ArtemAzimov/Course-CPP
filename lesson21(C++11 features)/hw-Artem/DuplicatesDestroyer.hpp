/*
TODO:
    *REVISION #1:
    [+] разделение private, public
    [+] hpp & cpp
    [+] unordered map
    [+] добавить проверку на size (сортировка. Затем проход №2 по хэшу содержимого файла)
    *REVISION #2:
    [+] убрать typedef
    [+] preprocessor / filesystem methods - кроссплатформа
    *REVISION #3:
    [+] компиляция на clang
    [-] объединить функцию print()
    [-] наследовать от абстрактного класса get() функции ?
    [-] привести к SOLID
    [-] unit тесты
    [-] замерить время рантайма из корня винды (chrono)
    [-] добавить мультитрединг
*/
#ifndef _DUPLICATES_DESTROYER_HPP
#define _DUPLICATES_DESTROYER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>


namespace fs = std::filesystem;

class DuplicateDestroyer{
private:
    // Для красивого вывода размеров файла можно использовать упорядоченную по убыванию мапу
    // std::map<uintmax_t, std::vector<fs::path>, std::greater<>> _allFiles;

    fs::path _path;
    // Мапа, содержащая пару Размер файла:Вектор путей файлов
    std::unordered_map<uintmax_t, std::vector<fs::path>> _allFiles;
    // Мапа, содержащая пару Хэш файла:Вектор путей файлов
    std::unordered_map<size_t, std::vector<fs::path>> _duplicates;
public:
    DuplicateDestroyer();
    DuplicateDestroyer(const std::string& userpath);

private:
    // Исключить папки .vscode и build из сканирования
    bool ignoredFolders(const fs::path& path);
    
    // Поиск по ключам в словаре. Проверка есть ли уже такой хэш
    bool checkKeyEntry(const size_t& hash);
    // Для группировки по размеру файлов
    bool checkKeyEntrySize(const uintmax_t& size);

    // Поиск по path файла в векторе
    bool checkFileEntry(const fs::path& file);
    // Для группировки по размеру файлов - поиск по path файла в векторе мапы
    bool checkFileEntrySize(const fs::path& file);

    // Создать в мапе ключ и запушить в вектор файл
    void createPair(size_t hash, fs::path file);
    // Для группировки по размеру файлов
    void createPairSize(uintmax_t size, fs::path file);
    
    // Найти в мапе ключ и запушить в вектор файл
    void addFile(size_t hash, fs::path file);
    // Для группировки по размеру файлов
    void addFileSize(uintmax_t size, fs::path file);

public:
    // Создает мапу <Размер файла : Файл>. Группирует Файлы по Размеру файла
    void getFileSize();

    // Фильтрует НЕдупликаты (удаляет ключи из мапы, где размер вектора <= 1)
    void filterNonDuplicates();

    // Сравнивает по хэшу содержимого
    void getFileContent();

    void print();

    void deleteDuplicates();
};

#endif // _DUPLICATES_DESTROYER_HPP