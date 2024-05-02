#include "TextEditorH.hpp"

int main(){
    cout << endl << "***TEXT EDITOR STARTED***" << endl << endl;
    TextEditor session1;
    std::string str;
    // if (run) {session1.help();}
    session1.help();

    while (run){
        cout << ">: ";
        std::getline(cin, str);
        session1.input_handler(str);
    }

    return 0;
}