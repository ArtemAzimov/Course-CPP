/*
3. Задача: Чтение данных из бинарного файла.
   - Создайте структуру данных, которая представляет информацию о студенте (имя, возраст, средний балл и т.д.).
   - Напишите программу, которая открывает бинарный файл, считывает данные о студенте из него и выводит их на экран.
   - Продемонстрируйте чтение нескольких структур из файла.
*/

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <filesystem>

using std::cin; using std::cout; using std::endl;

class Students{
public:
    struct Student{
        int id;
        std::string name;
        int age;
        int score;
        Student(const int& id, const std::string& name, const int& age, const int& score) : id(id), name(name), age(age), score(score){};
    };

    std::vector<Student*> STUD;
    Students(){}

    std::string getData(){
        std::string userInput;
        cout << "Waiting for user input >: ";
        std::getline(cin, userInput);
        return userInput;
    }

    void createStudent(){
        int id = std::stoi(getData());
        std::string name = getData();
        int age = std::stoi(getData());
        int score = std::stoi(getData());
        Student* pointerToStudent = new Student{id, name, age, score};
        STUD.push_back(pointerToStudent);
    }

    bool createFile(){
        if(std::filesystem::exists("students.bin")){
            return true;
        }
        else {return false;}
    }

    void createDataBase(){
        if(!createFile()){
            time_t t = time(0);
            std::string date_time = ctime(&t);
            std::fstream file("students.bin", std::ios::out);
            if (!file) {throw std::runtime_error("Failed to create file students.bin");}
            file << date_time << '\n';
            file.close();
        }
        std::fstream file("students.bin", std::ios::out | std::ios::app);
        if (!file) {throw std::runtime_error("Failed to open file students.bin");}
        for (auto it = STUD.begin(); it != STUD.end(); ++it){
            file << (*it)->id << "," << (*it)->name << "," << (*it)->age << "," << (*it)->score << ";\n";
        }
        file.close();
    }

    void getDataBase(){
        std::ifstream file("students.bin", std::ios::binary);
        // Пропустить первые 28 байт, в которых указана дата создания базы данных
        file.seekg(28, std::ios::beg);

        std::string data;
        while(std::getline(file, data, ';')){
            cout << data;
        }
    }
};

int main(){
    Students mystud;
    cout << "ENTER DATA IN FORMAT: id, name, age, score" << endl;
    
    cout << "Student 1: " << endl;
    mystud.createStudent();
    cout << "Student 2: " << endl;
    mystud.createStudent();
    cout << "Student 3: " << endl;
    mystud.createStudent();

    mystud.createDataBase();

    mystud.getDataBase();

    return 0;
}
