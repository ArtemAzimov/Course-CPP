#include "record.hpp"

Record::Record(int id, const std::string& title, const std::string& content)
    : id_(id), title_(title), content_(content) {}

int Record::getId() const {
    return id_;
}

std::string Record::getTitle() const {
    return title_;
}

std::string Record::getContent() const {
    return content_;
}

void Record::setTitle(const std::string& title) {
    title_ = title;
}

void Record::setContent(const std::string& content) {
    content_ = content;
}
