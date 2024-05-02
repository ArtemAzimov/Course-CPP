#include "TextEditorH.hpp"

int main(){
    TextEditor session1;
    std::string str;
    cout << "------------------------------" << endl << "***TEXT EDITOR STARTED SUCCESSFULLY***" << endl << endl; 
    session1.help();

    while (true){
        cout << ">: ";
        std::getline(cin, str);
        session1.input_handler(str);
    }

    return 0;
}