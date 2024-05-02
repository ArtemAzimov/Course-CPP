#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include "record.hpp"
#include <vector>

class Notebook {
public:
    int getNextId() const;
    void addRecord(const Record& record);
    void displayAllRecords() const;
    void searchRecord(const std::string& keyword) const;
    void updateRecord(int id, const std::string& newTitle, const std::string& newContent);
    void deleteRecord(int id);
    void saveRecordsToFile(const std::string& filename) const;
    void loadRecordsFromFile(const std::string& filename);

private:
    std::vector<Record> records_;
};

#endif // NOTEBOOK_H
