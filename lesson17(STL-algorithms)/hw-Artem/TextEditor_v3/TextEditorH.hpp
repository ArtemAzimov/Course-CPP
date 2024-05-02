#ifndef TEXT_EDITOR_HPP
#define TEXT_EDITOR_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstdio>

using std::cout; using std::cin; using std::endl;

enum class ErrorCode{
    UnableToOpen,
    UnableToRead,
    UnableToWrite,
    NoSuchFile,
    AlreadyCreated,
    NothingToSelect,
    NothingToDelete,
    IncorrectInput
};

class TextEditor{
private:
    std::string current_file;
    std::vector<std::string> userfilesVector;
public:
    TextEditor();
    ~TextEditor();

    void createFile(std::string input);

    // отдельная функция для создания файла если такового нет
    void createUserFiles();

    // отдельная функция для получения списка файлов
    void getUserFiles();

    // добавляет в список файлов клиента созданный файл
    void userfilesHandler(std::string filename);

    // удаляет (через временный файл) список файлов клиента при удалении файла
    void userfilesDeleter();

    void selectFile(std::string input);

    void writeString(std::string input);

    // вывод всех строк в файле за раз
    void readString();

    // список всех файлов клиента
    void listFiles();

    // удаляет файл, вызывает удалятель вектора файлов и удалятель списка файлов клиента, заново заполняет вектор
    void deleteFile();

    void help();

    // обработчик ввода из терминала
    void input_handler(std::string input);

    // принимает код ошибки, если ошибка фатальная вызывает run = false -> выход из программы
    void session_handler(ErrorCode errorcode);
};

#endif

/*  TO DO:
    + Enum class
    + выход при ошибке через стандартную функцию exit(1)
    - интерфейс
    - обновить итераторы, использовать STL-алгоритмы
    - динамически выделять память под string current_file и читать с ограничением (size строки)
    - userfilesVector выделять динамически + обновлять capacity
    - сделать linked list на историю изменений ?
    - принимать по string& ?
*/