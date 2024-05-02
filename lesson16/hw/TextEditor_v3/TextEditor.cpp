#include "TextEditorH.hpp"

TextEditor::TextEditor(){
    userfilesVector.reserve(10);
    createUserFiles();
    getUserFiles();
    current_file = "NULL";
}
TextEditor::~TextEditor(){}

void TextEditor::createFile(std::string input){
    std::string filename = input + ".txt";
    std::vector<std::string>::iterator it = std::find(userfilesVector.begin(), userfilesVector.end(), filename);
    if (it == userfilesVector.end()){
        userfilesVector.push_back(filename);

        std::fstream file;
        file.open(filename, std::ios::out);
        file.close();
        cout << "---* Now working in \"" << filename << '\"' << '.' << endl;

        userfilesHandler(filename);
        current_file = filename;
    }
    else{
        session_handler(ErrorCode::AlreadyCreated);
    }
}

void TextEditor::createUserFiles(){
    std::fstream file("userfiles.txt");
    if (file.is_open()){cout << "---* userfiles.txt is found" << endl;}
    else {std::fstream file("userfiles.txt", std::ios::out); cout << "---* userfiles.txt is created in this directory" << endl;}
}

void TextEditor::getUserFiles(){
    std::fstream file("userfiles.txt");
    if (file.is_open()){
        while (file){
            for (std::string s; std::getline(file, s); ) {userfilesVector.push_back(s);}
        }
    }
    else{
        session_handler(ErrorCode::UnableToOpen);
        exit(1);
    }
}

void TextEditor::userfilesHandler(std::string filename){
    std::fstream file;
    file.open("userfiles.txt", std::ios::out | std::ios::app);
    std::string str = filename + "\n";
    file << str;
}

void TextEditor::userfilesDeleter(){
    std::fstream file;
    std::fstream tempfile;
    file.open("userfiles.txt", std::ios::in);
    tempfile.open("temp.txt", std::ios::out);

    if (!file || !tempfile) {session_handler(ErrorCode::UnableToOpen);}
    else{
        while (file){
            for (std::string s; std::getline(file, s); ){
                if (s != current_file){
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

void TextEditor::selectFile(std::string input){
    std::string filename;
    filename = input + ".txt";
    std::vector<std::string>::iterator it = std::find(userfilesVector.begin(), userfilesVector.end(), filename);
    if (it == userfilesVector.end()) {session_handler(ErrorCode::UnableToOpen);}
    else {
        cout << filename << " selected" << endl;
        current_file = filename;
    }
}

void TextEditor::writeString(std::string input){
    std::fstream file;    
    file.open(current_file.c_str(), std::ios::out | std::ios::app);
    if(file.is_open()) {file << input << endl;}
    else {session_handler(ErrorCode::UnableToOpen);}
}

void TextEditor::readString(){
    cout << "---* Contents of file \"" << current_file << '\"' << endl;
    std::fstream file;
    file.open(current_file, std::ios::in);
    if (file.is_open()){
        int i = 0;
        while (file){
            for (std::string s; std::getline(file, s); )
            cout << s << endl;
            i++;
        }
        if (i == 0) {cout << "---* EMPTY" << endl;}
    }
    else {session_handler(ErrorCode::UnableToRead);}
}

void TextEditor::listFiles(){
    std::fstream file;
    file.open("userfiles.txt", std::ios::in);
    if (file.is_open()){
        while (file){
            for (std::string s; std::getline(file, s); )
            cout << s << endl;
        }
    }
    else {session_handler(ErrorCode::UnableToOpen);}
}

void TextEditor::deleteFile(){
    if (current_file == "NULL") {session_handler(ErrorCode::NothingToDelete);}
    else{
        remove(current_file.c_str());
        userfilesVector.clear();
        userfilesDeleter();
        current_file = "NULL";
        getUserFiles();
    }
}

void TextEditor::help(){
    cout << "---LIST OF COMMANDS---" << endl;
    cout << "create" << '\t' << '\t' << "ls" << '\t' << '\t' << "select" << '\t' << '\t' << "delete" << endl;
    cout << "write" << '\t' << '\t' << "read" << '\t' << '\t' << "help" << '\t' << '\t' << "exit" << endl << endl;
}

void TextEditor::input_handler(std::string input){
    std::string str;
    if (input == "create"){
        cout << "---Enter filename (without .txt) >: ";
        std::getline(cin, str);
        createFile(str);
    }
    else if (input == "ls"){
        cout << "---* List of user files: " << endl;
        listFiles();
    }

    else if (input == "select"){
        if (userfilesVector.empty()) {session_handler(ErrorCode::NothingToSelect);}
        else{
            cout << "---* Enter filename (without .txt) >: ";
            std::getline(cin, str);
            selectFile(str);
        }
    }
    else if (input == "write"){
        if (current_file == "NULL") {session_handler(ErrorCode::UnableToWrite);}
        else{
            cout << "---* Enter string >: ";
            std::getline(cin, str);
            writeString(str);
        }
    }
    else if (input == "read"){
        if (current_file == "NULL") {session_handler(ErrorCode::UnableToRead);}
        else{readString();}
    }
    else if (input == "help"){
        help();
    }
    else if (input == "delete"){
        deleteFile();
    }
    else if (input == "exit"){
        exit(1);
    }
    else {session_handler(ErrorCode::IncorrectInput);}
}

void TextEditor::session_handler(ErrorCode errorcode){
    static std::unordered_map<ErrorCode, std::string> errorCodeMap{
        {ErrorCode::UnableToOpen, "Unable to open \"userfiles.txt\"."},
        {ErrorCode::UnableToRead, "Unable to read from file."},
        {ErrorCode::UnableToWrite, "Unable to write to file."},
        {ErrorCode::NoSuchFile, "There is no such file in userfiles."},
        {ErrorCode::AlreadyCreated, "File with that name is arleady created."},
        {ErrorCode::NothingToSelect, "Nothing to select. Userfiles is empty."},
        {ErrorCode::NothingToDelete, "Nothing to delete. No file selected."},
        {ErrorCode::IncorrectInput, "Incorrect input. Type \"help\" for list of commands."}};
    cout << errorCodeMap[errorcode] << endl;
}