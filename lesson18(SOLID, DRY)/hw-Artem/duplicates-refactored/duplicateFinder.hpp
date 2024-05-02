#include <fstream>
#include <filesystem>
#include <vector>
#include <map>
#include <algorithm>

#include "printMsg.hpp"

/*
    TODO:
    1. Если указана другая директория (не там где .exe) - то неправильно открывает ifstream
    2. Если 2 разных файла оригинала удаляет все дубликаты, оставляя только 1 оригинал - надо сделать разделение
    3. Сравнивать hash файлов
    4. Сделать тесты generate
    5. Привести код к принципам SOLID
    6. Обновить cmakelists
*/

class FindDuplicate{
private:
    std::filesystem::path _path;
    std::vector<std::string> userfiles;

    // Содержит в себе вектор с именами файлов-дубликатов одного типа
    struct FullDuplicate{
        std::vector<std::string> _fileNames;
        FullDuplicate(std::vector<std::string> vec) : _fileNames(vec) {};
    };

    // Содержит в себе имена двух файлов дубликатов (пара)
    struct VectorContents{
        std::string _file1;
        std::string _file2;
        VectorContents(std::string filename1, std::string filename2) : _file1(filename1), _file2(filename2){}
    };

    std::vector<VectorContents*> pointersToVecStruct;
    std::vector<std::string> fulldupl;

    std::map<int, std::string> duplicatesMap;
public:
    FindDuplicate(){};

    void getPath(const std::filesystem::path& path){
        if(std::filesystem::exists(path)){
        _path = path;
        std::cout << "---* Path exists. \n";
        }
        else{
            throw(std::runtime_error("---* Path doesn't exists."));
        }
    }

    void Scan()
    {
        unsigned int files_count = 0;
        for (std::filesystem::directory_entry file : std::filesystem::directory_iterator(_path)){
            // Проверка на то что путь это файл, а не директория, т.к. для сравнения добавляю только файлы
            if (std::filesystem::is_regular_file(std::filesystem::path(file))){
                std::string foundfile = std::filesystem::path(file).filename().string();
                userfiles.push_back(foundfile);
                ++files_count;
            }
        }

        std::cout << "---* FILES FOUND: " << files_count << std::endl;
        for (auto it = userfiles.begin(); it != userfiles.end(); ++it){
            std::cout << *it << std::endl;
        }
        std::cout << std::endl;

        compareSize();
    }

    // TO DO: обнаружение разных оригиналов и их дубликатов, создание для каждого отдельного struct
    void compareSize(){
        std::map<std::string, int> map_userfiles;
        std::vector<std::string> duplicatesSize;
        for (auto it = userfiles.begin(); it != userfiles.end(); ++it){
            std::ifstream file(*it, std::fstream::ate | std::ios::binary);
            if (!file){throw std::runtime_error("Unable to open file in FUNC compareSize()");}
            std::ifstream::pos_type filesize = file.tellg();
            map_userfiles.insert(std::pair<std::string, int>(*it, filesize));
            file.close();
        }
        
        // задваивает названия файлов, нужна проверка перед push_back

        for (auto it = map_userfiles.begin(); it != map_userfiles.end(); ++it){
            for (auto it2 = map_userfiles.begin(); it2 != map_userfiles.end(); ++it2){
                if ((*it).first != (*it2).first){
                    if ((*it).second == (*it2).second){
                        
                    }
                }
            }
        }

        if (duplicatesSize.empty()){
            std::cout << "---* NO DUPLICATES FOUND" << std::endl;
            exit(1);
        }
        else{
            CompareContents();
        }
    }

    void CompareContents(){
        std::string cont1;
        std::string cont2;
        std::cout << "---* STARTING COMPARING BY FILE CONTENTS..." << std::endl;
        for (auto it = pointersToVecStruct.begin(); it != pointersToVecStruct.end(); ++it){
            std::string filename1 = (*it)->_file1;
            std::string filename2 = (*it)->_file2;

            std::ifstream file1 (filename1, std::ios::binary);
            if (!file1){throw std::runtime_error("Unable to open file in FUNC CompareContents()");}
            while (file1){
                std::getline(file1, cont1);
            }
            file1.close();

            std::ifstream file2 (filename2, std::ios::binary);
            if (!file2){throw std::runtime_error("Unable to open file in FUNC CompareContents()");}
            while (file2){
                std::getline(file2, cont2);
            }
            file2.close();

            if (cont1.compare(cont2) == 0){
                std::cout << "---* FOUND FULL DUPLICATE FILES: " << filename1 << '\t' << filename2 << std::endl;
                fulldupl.push_back(filename1);
                fulldupl.push_back(filename2);
            }
        }

        // TO DO: вынести в отдельный модуль
        std::string userinp;
        std::cout << R"(DELETE DUPLICATE FILES? "Y/N" >: )";
        std::getline(std::cin, userinp);
        if (userinp == "N"){exit(0);}
        else if (userinp == "Y"){
            if (fulldupl.empty()){
                std::cout << "---* SCAN FIRST" << std::endl;
            }
            else{
                std::cout << "---* DELETION OF DUPLICATES STARTED..." << std::endl;
                deleteDuplicates();
            }
        }
    }

    void deleteDuplicates(){
        // лютый хак чтобы удалялись копии названий файлов в векторе + удаляет первый элемент из вектора (как оригинал), чтобы не удалить
        sort(fulldupl.begin(), fulldupl.end());
        fulldupl.erase(unique(fulldupl.begin(), fulldupl.end() ), fulldupl.end());
        fulldupl.erase(fulldupl.begin());

        for (auto it = fulldupl.begin(); it != fulldupl.end(); ++it){
            std::filesystem::remove(*it);
        }
        std::cout << "---* DUPLICATES SUCCESSFULLY DELETED" << std::endl;
    }
};