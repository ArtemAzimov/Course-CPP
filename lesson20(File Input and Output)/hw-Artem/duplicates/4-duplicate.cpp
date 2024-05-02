#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <filesystem>
#include <vector>
#include <map>
#include <algorithm>

/*
    Если указана другая директория (не там где .exe) - то неправильно открывает ifstream
    Если 2 разных файла оригинала удаляет все дубликаты, оставляя только 1 оригинал - надо сделать разделение
*/

class FindDuplicate{
private:
    std::filesystem::path _path;
    std::vector<std::string> userfiles;
    std::vector<std::string> fulldupl;

    struct VectorContents{
        std::string _file1;
        std::string _file2;
        VectorContents(std::string filename1, std::string filename2) : _file1(filename1), _file2(filename2){}
    };

    std::vector<VectorContents*> pointersToVecStruct;
public:
    FindDuplicate(std::filesystem::path path) : _path(path){
        checkPath();
    }

    void checkPath(){
        if(std::filesystem::exists(_path)){
            std::cout << "---* Path exists" << std::endl;
            inputHandler();
        }
        else{
            std::cout << "---* Path IS WRONG" << std::endl;
        }
    }

    void inputHandler(){
        std::string userinp;
        std::cout << R"(START SCAN FOR DUPLICATE FILES? "Y/N" >: )";
        std::getline(std::cin, userinp);
        if (userinp == "N"){exit(0);}
        else if (userinp == "Y") {Scan();}
        else {inputHandler();}  // рекурсия ?
    }

    void Scan()
    {
        std::cout << "---* CHECK FOR DUPLICATED FILES STARTED" << std::endl;
        std::cout << "---* SCANNING CURRENT DIRECTORY..." << std::endl;
        
        int files_count = 0;
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
                        if(std::find(duplicatesSize.begin(), duplicatesSize.end(), (*it).first) == duplicatesSize.end()){
                            std::cout << "---* DUPLICATES BY FILE SIZE FOUND: " << (*it).first << '\t' << (*it2).first << std::endl;
                            duplicatesSize.push_back((*it).first);
                            duplicatesSize.push_back((*it2).first);
                            VectorContents* VecStruct = new VectorContents((*it).first, (*it2).first);
                            pointersToVecStruct.push_back(VecStruct);
                        }
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
        // лютый костыль чтобы удалялись копии названий файлов в векторе + удаляет первый элемент из вектора (как оригинал), чтобы не удалить
        sort(fulldupl.begin(), fulldupl.end());
        fulldupl.erase(unique(fulldupl.begin(), fulldupl.end() ), fulldupl.end());
        fulldupl.erase(fulldupl.begin());

        for (auto it = fulldupl.begin(); it != fulldupl.end(); ++it){
            std::filesystem::remove(*it);
        }
        std::cout << "---* DUPLICATES SUCCESSFULLY DELETED" << std::endl;
    }
};

int main(){
    std::string userinp;
    
    std::cout << R"(---* PATH FORMAT: C:\dir\dir)" << std::endl;
    std::cout << R"(---* Hit "ENTER" key or type "current" for using current .exe file directory)" << std::endl;
    std::cout << "Enter your path >: ";

    while(true)
    {
        std::getline(std::cin, userinp);
        std::filesystem::path path;

        if (userinp == "exit"){
            exit(0);
        }
        else if (userinp.length() == 0 || userinp == "current"){
            path = std::filesystem::current_path();
            std::cout << "---* Current path: " << path << " selected" << std::endl;
            FindDuplicate fd(path);
        }
        else{
            path = userinp;
            std::cout << "---* Path: " << path << " selected" << std::endl;
            FindDuplicate fd(path);
        }
    }

    return 0;
}