#include <Windows.h>
#include <iostream>

typedef int (__stdcall *DLL_function)(int);

int main(){
    /**
     *  Формат записи пути к библиотеке:
     *  "./lib.dll"
     *  "..\\lib.dll"
     *  или то же, но без .dll (LoadLibrary автоматически ставит .dll)
     */
    HINSTANCE DLL_id = LoadLibrary("./libsquare");

    if (!DLL_id) {
    std::cout << "Failed to load the library." << std::endl;
    return EXIT_FAILURE;
    }

    // "sqaure_a_num" - имя функции в .hpp
    DLL_function square_operation = (DLL_function)GetProcAddress(DLL_id, "square_a_num");
    if (!square_operation) {
    std::cout << "Failed to find the function." << std::endl;
    return EXIT_FAILURE;
    }

    for (int i = 0; i <= 10; i++)
    {
        std:: cout << "Square of " << i << " = " << square_operation(i) << std::endl;
    }

    return EXIT_SUCCESS;
}