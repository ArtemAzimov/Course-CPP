#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>

using std::cout; using std::cin; using std::endl;

bool run = true;

class TextEditor
{
private:
    std::string current_file;
    std::vector<std::string> userfilesVector;   // содержит в себе имена файлов клиента, обновляется при запуске и при удалении файла
    std::map<int, std::string> errorCodeMap;    // список ошибок по ключам
public:
    TextEditor()
    {
        session_handler_initializer();
        userfilesVector.reserve(10);
        getUserFiles();
        current_file = "NULL";
    }
    ~TextEditor(){}     // надо подумоть - динамически выделять память под string current_file и читать с ограничением (длина названия)
                        // userfilesVector выделить + обновлять capacity
                        // + сделать linked list на историю изменений ??
                        // принимать все по &string ??
                        // update comments (up)
                        // new stl-iterators
                        // enum for map and hashmap
                        // visual style
                        // интерфейс, hpp cpp etc

    void createFile(std::string input)
    {
        std::string filename = input + ".txt";
        std::vector<std::string>::iterator it = std::find(userfilesVector.begin(), userfilesVector.end(), filename);   // чек на наличие дубля файла
        if (it == userfilesVector.end())
        {
            userfilesVector.push_back(filename);

            std::fstream file;
            file.open(filename, std::ios::out);
            cout << "---Now working in \"" << filename << '\"' << '.' << endl;

            userfilesHandler(filename);
            current_file = filename;
        }
        else
        {
            session_handler(4);
        }
    }

    void getUserFiles()
    {
        std::fstream file;
        file.open("userfiles.txt", std::ios::out);
        file.close();
        file.open("userfiles.txt", std::ios::in);
        if (file.is_open())
        {
            while (file)
            {
                for (std::string s; std::getline(file, s); )
                    {
                        userfilesVector.push_back(s);
                    }
            }
        }
        else session_handler(0);
    }

    void userfilesHandler(std::string filename)     // добавляет в список файлов клиента созданный файл
    {
        std::fstream file;
        file.open("userfiles.txt", std::ios::out | std::ios::app);
        std::string str = filename + "\n";
        file << str;
    }

    void userfilesDeleter()     // удаляет (через временный файл) список файлов клиента при удалении файла
    {
        std::fstream file;
        std::fstream tempfile;
        file.open("userfiles.txt", std::ios::in);
        tempfile.open("temp.txt", std::ios::out);
        if (!file && !tempfile) {session_handler(0);}
        else
        {
            while (file)    
            {
                for (std::string s; std::getline(file, s); )
                {
                    if (s != current_file)
                    {
                        tempfile << s + "\n";
                    }
                }
            }
            file.close();
            tempfile.close();
            remove("userfiles.txt");
            rename("temp.txt", "userfiles.txt");
        }
    }

    void selectFile(std::string input)
    {
        std::string filename;
        filename = input + ".txt";
        std::vector<std::string>::iterator it = std::find(userfilesVector.begin(), userfilesVector.end(), filename);   // чек на существование такого файла
        if (it == userfilesVector.end() + 1)
        {
            session_handler(3);
        }
        else
        {
            cout << filename << " selected" << endl;
            current_file = filename;
        }
    }

    void writeString(std::string input)     // запись строки в файл
    {
        std::fstream file;    
        file.open(current_file.c_str(), std::ios::out | std::ios::app);
        if(file.is_open())
        {
            file << input << endl;
        } 
        else session_handler(0);
    }

    void readString()       // вывод всех строк в файле за раз
    {
        cout << "---Contents of file \"" << current_file << '\"' << endl;
        std::fstream file;
        file.open(current_file, std::ios::in);
        if (file.is_open())
        {
            while (file)
            {
                for (std::string s; std::getline(file, s); )
                cout << s << endl;
            }
        }
        else session_handler(2);
    }

    void listFiles()        // список всех файлов клиента
    {
        std::fstream file;
        file.open("userfiles.txt", std::ios::in);
        if (file.is_open())
        {
            while (file)
            {
                for (std::string s; std::getline(file, s); )
                cout << s << endl;
            }
        }
        else session_handler(0);
    }

    void deleteFile()       // удаляет файл, вызывает удалятель вектора файлов и удалятель списка файлов клиента, заново заполняет вектор
    {
        if (current_file == "NULL")
        {
            session_handler(6);
        }
        else
        {
            remove(current_file.c_str());
            userfilesVector.clear();
            userfilesDeleter();
            current_file = "NULL";
            getUserFiles();
        }
    }

    void help()
    {
        cout << "---LIST OF COMMANDS---" << endl;
        cout << "create" << '\t' << '\t' << "ls" << '\t' << '\t' << "select" << '\t' << '\t' << "delete" << endl;
        cout << "write" << '\t' << '\t' << "read" << '\t' << '\t' << "help" << '\t' << '\t' << "exit" << endl << endl;
    }

    void input_handler(std::string input)       // обработчик ввода из терминала
    {
        std::string str;
        if (input == "create")
        {
            cout << "---Enter filename >: ";
            std::getline(cin, str);
            createFile(str);
        }
        else if (input == "ls")
        {
            cout << "---List of user files: " << endl;
            listFiles();
        }

        else if (input == "select")
        {
            if (userfilesVector.empty()) {session_handler(7);}
            else
            {
                cout << "---Enter filename >: ";
                std::getline(cin, str);
                selectFile(str);
            }
        }
        else if (input == "write")
        {
            if (current_file == "NULL") {session_handler(5);}
            else
            {
                cout << "---Enter string >: ";
                std::getline(cin, str);
                writeString(str);
            }
        }
        else if (input == "read")
        {
            if (current_file == "NULL") {session_handler(5);}
            else{readString();}
        }
        else if (input == "help")
        {
            help();
        }
        else if (input == "delete")
        {
            deleteFile();
        }
        else if (input == "exit")
        {
            run = false;
        }
        else session_handler(5);
    }

    void session_handler_initializer ()
    {
        errorCodeMap.insert({0, "Fatal error. Exiting application..."}); // constructor, input_handler(write/read NULL-case)
        errorCodeMap.insert({1, "Unable to open file when adding string"}); // writeString
        errorCodeMap.insert({2, "Unable to open file when reading string"}); // readString
        errorCodeMap.insert({3, "There is no such file"}); // selectFile
        errorCodeMap.insert({4, "File already created"}); // createFile
        errorCodeMap.insert({5, "Incorrect input"}); // input_handler
        errorCodeMap.insert({6, "Nothing to delete"}); // deleteFIle
        errorCodeMap.insert({7, "Nothing to select"}); // input_handler(select)
    }

    void session_handler(int errorcode)     // принимает код ошибки, если ошибка фатальная вызывает run = false -> выход из программы
    {
        for (auto i = errorCodeMap.begin(); i != errorCodeMap.end(); i++)
        {
            if (i->first == errorcode)
            {
                if (i->first == 0) 
                {
                    cout << i->second << endl;
                    run = false;
                }
                else cout << "Error code " << i->first << ". " << i->second << '.' << endl;
            }
        }
    }
};

int main()
{
    cout << endl << "***TEXT EDITOR STARTED***" << endl << endl;
    TextEditor session1;
    std::string str;
    if (run) session1.help();

    while (run)
    {
        cout << ">: ";
        std::getline(cin, str);
        session1.input_handler(str);
    }

    return 0;
}