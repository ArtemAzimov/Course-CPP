#pragma once // .hpp - хедер, заголовочный файл НЕ ЯВЛЯЕТСЯ точкой интерпретации
            // компилятор их не компилирует, использует как хранилище для объявлений

#include <string> // подключение из системы
#include "AbsCard.hpp" // подключение из той же директории

class ProgrammerCard : public AbsCard
{
    int iq;
    std::string language;
public:
    ProgrammerCard(const int id, const std::string& name, unsigned salary, signed iq, std::string language)
            : AbsCard (id, name, salary), iq(iq), language(language) {}

    std::string getInfo() override;

    ~ProgrammerCard() = default; // ??? ЧТО ЕНТО ЗНАЧИТ?
};