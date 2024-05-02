#include "duplicateFinder.hpp"

#include <unordered_map>

enum class InputVars{
    Help,
    Start,
    Exit,
    null
};

static std::unordered_map<InputVars, std::string> mapInputVars = {
    {InputVars::Help, "help"},
    {InputVars::Start, "start"},
    {InputVars::Exit, "exit"}
};

InputVars getInput(const std::string& userinp){
    for (auto it = mapInputVars.begin(); it != mapInputVars.end(); ++it){
        if (userinp == (*it).second){
            return (*it).first;
        }
    }
    return InputVars::null;
}

int main(){
    std::string userinp;
    std::string userPath;
    std::filesystem::path path;
    PrintMsg print;
    FindDuplicate dup;

    print.welcome();

    // Проверка на инпут и вызов метода с соответствующим аргументом path
    std::getline(std::cin, userPath);
    if (userPath.length() == 0){
        path = std::filesystem::current_path();

        std::cout << "---* Current path: " << path << " selected" << std::endl;
        dup.getPath(path);
    }
    else{
        path = userPath;
        print.path(path);
        dup.getPath(path);
    }

    while(true)
    {
        try{
            switch (getInput(userinp)){
            case InputVars::Help:
                print.help();
                break;
            case InputVars::Start:
                print.start();
                std::getline(std::cin, userinp);
                if (userinp == "Y"){
                    print.scan();
                    dup.Scan();
                }
                break;
            case InputVars::Exit:
                print.exit();
                exit(0);
            case InputVars::null:
                throw(std::runtime_error("Invalid input."));
                break;
            default:
                throw(std::runtime_error("Something went wrong."));
                break;
            }
        }
        catch(const std::exception& e){
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}