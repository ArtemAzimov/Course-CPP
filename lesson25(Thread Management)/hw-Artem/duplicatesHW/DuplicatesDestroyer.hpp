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
    [+] компиляция на clang++
    [+] объединить функцию print()
    [+] темплейт применить к функциям check, create, add, т.к. дублируются
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

namespace Duplicates_namespace{
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
    template <typename K>
    bool checkKeyEntry(const std::unordered_map<K, std::vector<fs::path>>& map, const K& key);

    // Поиск по path файла в векторе
    template <typename K>
    bool checkFileEntry(const std::unordered_map<K, std::vector<fs::path>>& map, const fs::path& file);

    // Создать в мапе ключ и запушить в вектор файл
    template <typename K>
    void createPair(std::unordered_map<K, std::vector<fs::path>>& map, const K key, const fs::path file);
    
    // Найти в мапе ключ и запушить в вектор файл
    template <typename K>
    void addFile(std::unordered_map<K, std::vector<fs::path>>& map, const K key, const fs::path file);

public:
    // Создает мапу <Размер файла : Файл>. Группирует Файлы по Размеру файла
    void getFileSize();

    // Фильтрует НЕдупликаты (удаляет ключи из мапы, где размер вектора <= 1)
    void filterNonDuplicates();

    // Сравнивает по хэшу содержимого
    void getFileContent();

    template<typename K>
    void print(const std::unordered_map<K, std::vector<fs::path>>& _primaryVector);

    // void deleteDuplicates();
};
} // end of namespace Duplicates_namespace

#endif // _DUPLICATES_DESTROYER_HPP