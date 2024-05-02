#ifndef RECORD_H
#define RECORD_H

#include <string>

class Record {
public:
    Record(int id, const std::string& title, const std::string& content);

    int getId() const;
    std::string getTitle() const;
    std::string getContent() const;

    void setTitle(const std::string& title);
    void setContent(const std::string& content);

private:
    int id_;
    std::string title_;
    std::string content_;
};

#endif // RECORD_H

