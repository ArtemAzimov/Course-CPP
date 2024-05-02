#include "notebook.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

int Notebook::getNextId() const {
    if (records_.empty()) {
        return 1; // Если записей нет, возвращаем идентификатор 1
    } else {
        // Ищем максимальный идентификатор среди существующих записей
        auto maxId = std::max_element(records_.begin(), records_.end(),
            [](const Record& record1, const Record& record2) {
                return record1.getId() < record2.getId();
            });

        return maxId->getId() + 1; // Возвращаем следующий по порядку идентификатор
    }
}


void Notebook::addRecord(const Record& record) {
    records_.push_back(record);
    std::cout << "Запись успешно добавлена.\n";
}

void Notebook::displayAllRecords() const {
    if (records_.empty()) {
        std::cout << "Записи отсутствуют.\n";
        return;
    }

    std::cout << "Все записи:\n";
    for (const auto& record : records_) {
        std::cout << "ID: " << record.getId() << "\n";
        std::cout << "Заголовок: " << record.getTitle() << "\n";
        std::cout << "Содержимое: " << record.getContent() << "\n\n";
    }
}

void Notebook::searchRecord(const std::string& keyword) const {
    std::vector<Record> matchedRecords;

    for (const auto& record : records_) {
        if (record.getTitle().find(keyword) != std::string::npos ||
            record.getContent().find(keyword) != std::string::npos) {
            matchedRecords.push_back(record);
        }
    }

    if (matchedRecords.empty()) {
        std::cout << "Записи с заданным ключевым словом не найдены.\n";
        return;
    }

    std::cout << "Записи с ключевым словом \"" << keyword << "\":\n";
    for (const auto& record : matchedRecords) {
        std::cout << "ID: " << record.getId() << "\n";
        std::cout << "Заголовок: " << record.getTitle() << "\n";
        std::cout << "Содержимое: " << record.getContent() << "\n\n";
    }
}

void Notebook::updateRecord(int id, const std::string& newTitle, const std::string& newContent) {
    auto it = std::find_if(records_.begin(), records_.end(), [id](const Record& record) {
        return record.getId() == id;
    });

    if (it == records_.end()) {
        std::cout << "Запись с указанным ID не найдена.\n";
        return;
    }

    it->setTitle(newTitle);
    it->setContent(newContent);

    std::cout << "Запись успешно обновлена.\n";
}

void Notebook::deleteRecord(int id) {
    auto it = std::find_if(records_.begin(), records_.end(), [id](const Record& record) {
        return record.getId() == id;
    });

    if (it == records_.end()) {
        std::cout << "Запись с указанным ID не найдена.\n";
        return;
    }

    records_.erase(it);

    std::cout << "Запись успешно удалена.\n";
}

void Notebook::saveRecordsToFile(const std::string& filename) const {
    std::ofstream file(filename);

    if (!file) {
        std::cout << "Ошибка при открытии файла для сохранения.\n";
        return;
    }

    for (const auto& record : records_) {
        file << record.getId() << "\n";
        file << record.getTitle() << "\n";
        file << record.getContent() << "\n";
    }

    std::cout << "Записная книжка сохранена в файле.\n";
}

void Notebook::loadRecordsFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cout << "Ошибка при открытии файла для загрузки.\n";
        return;
    }

    records_.clear();

    int id;
    std::string title;
    std::string content;

    while (file >> id) {
        std::getline(file, title);
        std::getline(file, content);
        records_.emplace_back(id, title, content);
    }

    std::cout << "Записная книжка загружена из файла.\n";
}
