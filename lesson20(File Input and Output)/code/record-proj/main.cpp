#include <iostream>
#include <limits>

#include "notebook.hpp"

enum class Action
{
    Create = 1,
    ViewAll,
    Search,
    Update,
    Delete,
    SaveToFile,
    LoadFromFile,
    Exit
};

int main()
{
    Notebook notebook;
    std::string filename = "notebook.txt";

    notebook.loadRecordsFromFile(filename);

    std::string keyword;
    int id;
    std::string title, content;
    int choice = 0;
    std::string input;

    do
    {
        std::cout << "1. Создать новую запись\n";
        std::cout << "2. Просмотреть все записи\n";
        std::cout << "3. Поиск записи по ключевому слову\n";
        std::cout << "4. Обновить запись по идентификатору\n";
        std::cout << "5. Удалить запись по идентификатору\n";
        std::cout << "6. Сохранить записи в файл\n";
        std::cout << "7. Загрузить записи из файла\n";
        std::cout << "8. Выйти\n";
        std::cout << "Выберите действие: ";

        // Проверка на ввод целого числа
        while (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. Попробуйте снова: ";
        }

        // Очистка буфера ввода
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        try
        {
            Action action = static_cast<Action>(choice);

            switch (action)
            {
            case Action::Create:
                // Обработка создания новой записи
                std::cout << "Введите заголовок записи: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Введите содержимое записи: ";
                std::getline(std::cin, content);
                notebook.addRecord(Record(notebook.getNextId(), title, content));
                break;
            case Action::ViewAll:
                // Обработка просмотра всех записей
                notebook.displayAllRecords();
                break;
            case Action::Search:
                // Обработка поиска записи по ключевому слову
                std::cout << "Введите ключевое слово для поиска: ";
                std::cin.ignore();
                std::getline(std::cin, keyword);
                notebook.searchRecord(keyword);
                break;
            case Action::Update:
                // Обработка обновления записи по идентификатору
                std::cout << "Введите идентификатор записи: ";
                std::cin >> id;
                std::cout << "Введите новый заголовок записи: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Введите новое содержимое записи: ";
                std::getline(std::cin, content);
                notebook.updateRecord(id, title, content);
                break;
            case Action::Delete:
                // Обработка удаления записи по идентификатору
                std::cout << "Введите идентификатор записи: ";
                std::cin >> id;
                notebook.deleteRecord(id);
                break;
            case Action::SaveToFile:
                // Обработка сохранения записей в файл
                notebook.saveRecordsToFile(filename);
                break;
            case Action::LoadFromFile:
                // Обработка загрузки записей из файла
                notebook.loadRecordsFromFile(filename);
                break;
            case Action::Exit:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Некорректный выбор. Попробуйте снова.\n";
                break;
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "Ошибка: " << e.what() << "\n";
        }

        std::cout << "\n";
    } while (choice != static_cast<int>(Action::Exit));

    return 0;
}
