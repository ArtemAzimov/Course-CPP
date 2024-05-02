#include <fstream>
#include <iostream>

int main()
{
    // std::ofstream outFile("input.txt");
    {
        std::ifstream inputFile("input.txt");
        if (inputFile.is_open())
        {
            // Файл успешно открыт, можно выполнять операции с ним
            // Например, читать данные из файла
            std::string line;
            while (std::getline(inputFile, line))
            {
                // Обработка данных из файла
                std::cout << line << std::endl;
            }
            // inputFile.close(); // Закрытие файла
        }
        else
        {
            // Ошибка открытия файла
            std::cout << "Не удалось открыть файл!" << std::endl;
        }
    }
    

    return 0;
}