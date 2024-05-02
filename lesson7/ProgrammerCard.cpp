#include "ProgrammerCard.hpp"

std::string ProgrammerCard::getInfo()
{
    std::string info;
    info = '|' + std::to_string(id);
    info += '|' + name;
    info += '|' + std::to_string(salary);
    info += '|' + language;
    info += '|' + std::to_string(iq) + '|';

    return info;
}