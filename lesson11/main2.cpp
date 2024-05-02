#define MACROS       // заменяет все NAME на void

#ifdef MACROS           // если макрос был гдето объявлен до этой директивы
    int g_var = 10;     // нужон для кроссплатформенности
#endif

#ifdef _WIN64
    // CODE
#endif

#ifdef __unix
    // code
#endif

#ifndef MACROS         // если не определен
    // code
#endif
