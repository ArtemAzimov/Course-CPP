# Стандарт C++11
## Введение
Введение в C++11 является ключевым шагом в развитии языка программирования C++. C++11 представляет собой новую стандартную версию C++, которая была выпущена в 2011 году. Эта версия внесла множество новых особенностей и улучшений, которые значительно расширяют возможности языка и упрощают разработку программ.

Некоторые из ключевых особенностей C++11, которые мы будем рассматривать в этой лекции, включают:

1. Ключевое слово "auto": Оно позволяет автоматически выводить тип переменной на основе значения, с которым она инициализируется. Это упрощает код и делает его более гибким.

2. Цикл "for" по диапазону: Это новый тип цикла "for", который позволяет легко итерироваться по элементам контейнера, таким как массивы, векторы и строки, без необходимости работы с индексами.

3. Ключевое слово "nullptr": Оно представляет явное значение нулевого указателя и является более безопасной и ясной альтернативой использованию NULL или 0.

4. Делегирующие конструкторы: Они позволяют одному конструктору вызывать другой конструктор в том же классе, что способствует повторному использованию кода и упрощает инициализацию объектов.

Мы рассмотрим каждую из этих особенностей более подробно в течение лекции и рассмотрим примеры их использования. Понимание этих новых возможностей C++11 поможет вам писать более эффективный и современный код на языке C++.

## Ключевое слово "auto"

- Введение ключевого слова "auto" в C++11 (5 минут)
  - Объяснение назначения ключевого слова "auto" в C++11.
  - Упоминание о его роли в выводе типов переменных.

- Упрощение вывода типов с помощью ключевого слова "auto" (10 минут)
  - Объяснение преимуществ автоматического вывода типов.
  - Как "auto" позволяет избежать явного указания типа переменной при объявлении.
  - Сравнение с явным указанием типа и показ примеров, иллюстрирующих удобство использования "auto".

- Примеры использования ключевого слова "auto" при объявлении переменных (10 минут)
  - Демонстрация конкретных примеров, показывающих синтаксис использования "auto".
  - Использование "auto" для объявления переменных, инициализированных литералами, выражениями или вызовами функций.
  - Рассмотрение различных типов переменных, включая примитивные типы данных и пользовательские типы.

- Преимущества и потенциальные ошибки при использовании "auto" (5 минут)
  - Обсуждение преимуществ использования "auto" для упрощения кода и облегчения его чтения.
  - Упоминание о возможных проблемах, связанных с использованием "auto".
  - Объяснение важности четкости и понятности кода при использовании "auto".

Введение ключевого слова "auto" в C++11 составляет важную часть обновлений языка. Ключевое слово "auto" используется для автоматического вывода типа переменной на основе значения, с которым она инициализируется. Это позволяет программистам избежать явного указания типа переменной при ее объявлении, делая код более компактным и гибким.

Роль ключевого слова "auto" заключается в упрощении вывода типов. Вместо того чтобы указывать тип переменной явно, вы можете использовать "auto", и компилятор самостоятельно определит соответствующий тип на основе инициализирующего значения. Это особенно полезно при работе с сложными типами данных или при использовании шаблонов.

Использование "auto" позволяет сократить объем кода, улучшить его читаемость и сделать его более устойчивым к изменениям. Вместо того чтобы повторять тип переменной несколько раз, компилятор самостоятельно выведет тип из контекста и присвоит его переменной, что существенно упрощает кодирование.

Ключевое слово "auto" представляет собой мощный инструмент в C++11, позволяющий программистам писать более ясный и эффективный код, особенно при работе с сложными типами данных или при использовании шаблонов.

Упрощение вывода типов с помощью ключевого слова "auto" представляет существенное преимущество в C++11. Вот некоторые объяснения и примеры, иллюстрирующие, как "auto" упрощает работу с типами переменных:

1. Избегание явного указания типа переменной: При использовании "auto" вместо явного указания типа, компилятор самостоятельно определяет тип переменной на основе инициализирующего значения. Это особенно полезно при работе с сложными типами данных, такими как итераторы контейнеров или типы, возвращаемые из функций.

   Пример:
   ```cpp
   auto x = 10; // Компилятор автоматически определит тип x как int.
   auto name = "John"; // Компилятор автоматически определит тип name как const char*.
   auto it = container.begin(); // Компилятор автоматически определит тип it как итератор контейнера.
   ```

2. Удобство использования: Использование "auto" позволяет сократить количество кода и сделать его более лаконичным и читаемым. Вместо того, чтобы явно указывать тип переменной, вы можете использовать "auto" и дать компилятору заботу о типе.

   Пример:
   ```cpp
   // Без использования auto:
   std::vector<std::string>::iterator it = container.begin();
   std::unordered_map<int, std::string>::iterator it = map.begin();

   // С использованием auto:
   auto it = container.begin(); // Компилятор самостоятельно определит тип итератора.
   auto it = map.begin(); // Компилятор самостоятельно определит тип итератора.
   ```

   Использование "auto" позволяет избежать повторений типов, особенно при работе с длинными и сложными типами данных, что делает код более компактным и улучшает его читаемость.

   Пример:
   ```cpp
   // Без использования auto:
   std::unordered_map<int, std::vector<std::pair<std::string, int>>> myMap;
   std::unordered_map<int, std::vector<std::pair<std::string, int>>>::iterator it = myMap.begin();

   // С использованием auto:
   auto it = myMap.begin(); // Компилятор самостоятельно определит тип итератора.
   ```

   В этом примере, использование "auto" позволяет избежать длинного и сложного повторения типа итератора контейнера.

В целом, использование ключевого слова "auto" значительно упрощает работу с типами переменных, делает код более компактным, читаемым

Примеры использования ключевого слова "auto" при объявлении переменных:

1. Инициализация литералами:
```cpp
auto x = 10; // x будет иметь тип int.
auto name = "John"; // name будет иметь тип const char*.
auto pi = 3.14; // pi будет иметь тип double.
```

2. Инициализация выражениями:
```cpp
auto sum = a + b; // sum будет иметь тип, соответствующий результату сложения a и b.
auto result = calculateResult(); // result будет иметь тип, возвращаемый функцией calculateResult().
auto average = (x + y) / static_cast<double>(count); // average будет иметь тип double.
```

3. Инициализация вызовами функций:
```cpp
auto value = getValue(); // value будет иметь тип, возвращаемый функцией getValue().
auto size = container.size(); // size будет иметь тип, возвращаемый функцией size() контейнера.
```

4. Различные типы переменных:
```cpp
auto age = 25; // age будет иметь тип int.
auto flag = true; // flag будет иметь тип bool.
auto price = 19.99; // price будет иметь тип double.
auto message = std::string("Hello"); // message будет иметь тип std::string.
auto result = someFunction(); // result будет иметь тип, возвращаемый функцией someFunction().
```

Примечание: Ключевое слово "auto" позволяет компилятору самостоятельно определить тип переменной на основе ее инициализации. Это удобно при работе с различными типами данных, включая как примитивные, так и пользовательские типы.

Преимущества использования ключевого слова "auto":

1. Упрощение кода и облегчение его чтения: Использование "auto" позволяет избежать повторного указания типов переменных, особенно в случае сложных типов данных или вложенных шаблонов. Это делает код более компактным, улучшает его читаемость и упрощает его понимание.

2. Гибкость и поддержка изменений: Используя "auto", вы делегируете определение типа компилятору, что делает код более гибким и способным поддерживать изменения в дальнейшем. Если тип переменной изменится, вам необходимо будет вносить изменения только в одном месте - в инициализации переменной.

3. Улучшение производительности: Использование "auto" может помочь избежать ненужных копирований или преобразований типов, так как компилятор самостоятельно выбирает наиболее эффективные операции на основе типа инициализирующего значения.

Возможные проблемы, связанные с использованием "auto":

1. Неясность и неоднозначность: Иногда использование "auto" может привести к неопределенности относительно типа переменной, особенно если инициализирующее значение имеет неявный тип или является результатом сложного выражения. В таких случаях может быть полезно явно указать тип для улучшения читаемости и ясности кода.

2. Потеря информации о типе: Использование "auto" может скрыть информацию о типе переменной, особенно если используется в шаблонном коде. Это может затруднить отладку или понимание кода другим программистам.

Важность четкости и понятности кода:

Независимо от использования "auto" или явного указания типа переменной, важно поддерживать четкость и понятность кода. Правильное идентифицирование переменных и выбор осмысленных имен переменных является важным аспектом написания качественного кода. Комментарии и документация также могут помочь другим программистам в понимании кода и его намерений.

## Ограничения традиционного цикла for:

Традиционный цикл for в C++ имеет некоторые ограничения, которые могут усложнять его использование:

1. Неявное указание размера контейнера: При использовании традиционного цикла for, чтобы выполнить итерацию по элементам контейнера, необходимо явно указывать его размер или использовать итераторы, что может быть неудобно и приводить к ошибкам.

2. Необходимость работы с индексами: Традиционный цикл for требует явного использования индексов для доступа к элементам контейнера. Это может усложнять кодирование, особенно при работе с большими и сложными структурами данных.

Цикл for по диапазону в C++11:

Цикл for по диапазону (range-based for loop) представляет более удобный и интуитивно понятный способ выполнения итераций по элементам контейнера. Он был введен в C++11 и позволяет проходить по всем элементам контейнера без явного указания его размера или использования индексов.

Синтаксис цикла for по диапазону:
```cpp
for (auto element : container) {
  // Код для обработки элемента
}
```

Примеры использования цикла for по диапазону:
```cpp
std::vector<int> numbers = {1, 2, 3, 4, 5};

for (auto number : numbers) {
  std::cout << number << " ";
}
// Вывод: 1 2 3 4 5

std::string message = "Hello";

for (auto ch : message) {
  std::cout << ch << " ";
}
// Вывод: H e l l o
```

Преимущества цикла for по диапазону:

1. Удобство и читаемость: Цикл for по диапазону упрощает и улучшает читаемость кода, так как не требует явного указания размера контейнера или работы с индексами. Это делает код более компактным и легким для понимания.

2. Безопасность: Цикл for по диапазону обеспечивает безопасность при обходе контейнера, так как автоматически определяет начало и конец диапазона, предотвращая ошибки выхода за пределы контейнера.

3. Простота использования с различными контейнерами: Цикл for по диапазону может использоваться с различными контейнерами, включая массивы, векторы, списки, наборы и другие, а также с пользовательскими типами

## Проблема использования NULL и 0 для нулевых указателей:

В C++ до стандарта C++11, для обозначения нулевого указателя обычно использовались макросы NULL или 0. Однако использование NULL и 0 может приводить к проблемам и неоднозначностям:

1. Амбигвенность: В некоторых случаях, при смешивании указателей и целочисленных типов, использование NULL или 0 может вызывать неоднозначности и неожиданное поведение программы.

2. Типизация: NULL и 0 не имеют строго определенного типа, что может вызывать проблемы при использовании перегрузок функций или шаблонов.

3. Неясность: NULL и 0 могут быть иногда путаницей, особенно для новых разработчиков, не знакомых с историей их использования.

Ключевое слово nullptr в C++11:

В стандарте C++11 было представлено ключевое слово nullptr, которое служит для явного указания нулевого указателя.

Преимущества использования nullptr:

1. Типизированность: nullptr имеет явно определенный тип std::nullptr_t, что помогает избежать неоднозначностей и проблем с типизацией.

2. Безопасность: Использование nullptr предотвращает неоднозначности, связанные с NULL и 0, и помогает избежать ошибок, связанных с нулевыми указателями.

3. Код читаемее: Использование nullptr улучшает читаемость кода и ясно указывает на намерение создания нулевого указателя.

Примеры использования nullptr:

```cpp
int* ptr = nullptr; // Инициализация указателя нулевым значением

if (ptr == nullptr) {
  // Проверка на нулевой указатель
  // ...
}

void foo(int* ptr) {
  if (ptr == nullptr) {
    // Обработка нулевого указателя
    // ...
  }
}

```

Использование nullptr помогает повысить безопасность типов и предотвращает неоднозначности, связанные с использованием NULL и 0 в качестве нулевых указателей.
## Понятие конструкторов и их роль в инициализации объектов:

Понятие делегирующих конструкторов в C++11:

Делегирующие конструкторы - это нововведение, представленное в стандарте C++11, которое позволяет одному конструктору вызывать другой конструктор в том же классе для выполнения части инициализации.

Синтаксис делегирующих конструкторов:

```cpp
class MyClass {
public:
  MyClass(int x, int y) {
    // Инициализация объекта
  }

  MyClass(int x) : MyClass(x, 0) {
    // Делегирование конструктора MyClass(int x, int y)
  }
};
```

Преимущества использования делегирующих конструкторов:

1. Упрощение кода: Делегирующие конструкторы позволяют избежать дублирования кода, когда несколько конструкторов имеют одинаковую инициализацию членов класса.

2. Повторное использование кода: Делегирующие конструкторы позволяют повторно использовать код инициализации внутри класса, что упрощает его обновление и поддержку.

3. Гибкость и расширяемость: Делегирующие конструкторы предоставляют гибкость в настройке инициализации объектов, позволяя вызывать различные комбинации конструкторов в зависимости от требуемых параметров.

Примеры использования делегирующих конструкторов:

```cpp
class Point {
public:
  Point() : Point(0, 0) {
    // Делегирование конструктора Point(int x, int y)
  }

  Point(int x, int y) {
    // Инициализация объекта
  }
};

class Rectangle {
public:
  Rectangle() : Rectangle(0, 0, 0, 0) {
    // Делегирование конструктора Rectangle(int x, int y, int width, int height)
  }

  Rectangle(int width, int height, int x, int y) {
    // Инициализация объекта
  }
};

// Пример использования делегирующего конструктора
Point p1;  // Используется конструктор Point()
Point p2(5, 10);  // Используется конструктор Point(int x, int y)

Rectangle r1;  // Используется конструктор Rectangle()
Rectangle r2(10, 20, 5, 5);  // Используется конструктор Rectangle(int width, int height, int x, int y)
```

В приведенных примерах делегирующие конструкторы позволяют установить значения членов класса с помощью других конструкторов, что позволяет упростить инициализацию объектов и избежать дублирования кода.

Использование делегирующих конструкторов повышает гибкость, удобство и повторное использование кода при инициализации объектов.

## Класс обертка
`std::function` - это класс-обертка, предоставляемый в стандартной библиотеке C++, который позволяет хранить и вызывать различные типы функций, включая функции, функциональные объекты, лямбда-функции и указатели на функции.

`std::function` обеспечивает единый интерфейс для работы с функциями различных типов, что позволяет легко передавать и хранить функции как параметры или переменные.

Основные возможности и использование `std::function`:

1. Хранение функций: `std::function` позволяет хранить функции различных типов в одной переменной, что полезно, когда требуется передать функцию в качестве параметра или хранить ее в коллекции.

2. Вызов функций: `std::function` позволяет вызывать хранимую функцию с помощью оператора `()`. Это обеспечивает единый способ вызова функций различных типов.

3. Параметры и возвращаемые значения: `std::function` может хранить функции с различными параметрами и возвращаемыми значениями. Это позволяет гибко работать с функциями, которые имеют разные сигнатуры.

4. Применение лямбда-функций: `std::function` часто используется для хранения и передачи лямбда-функций. Это позволяет создавать и использовать анонимные функции в контексте, где требуется определенный тип функции.

Пример использования `std::function`:

```cpp
#include <iostream>
#include <functional>

// Пример функции
int add(int a, int b) {
  return a + b;
}

int main() {
  std::function<int(int, int)> func;  // Объявление std::function для функций с сигнатурой int(int, int)

  func = add;  // Присваивание функции add

  int result = func(2, 3);  // Вызов хранимой функции

  std::cout << result << std::endl;  // Вывод результата (5)

  return 0;
}
```

В этом примере `std::function` используется для хранения и вызова функции `add`. Оператор `()` используется для вызова хранимой функции, и результат выводится на экран.

`std::function` является мощным инструментом, который облегчает работу с функциями различных типов и обеспечивает большую гибкость при разработке программ на C++.

Дополнительные возможности и использование `std::function`:

5. Полиморфное использование: `std::function` позволяет полиморфное использование функций, то есть вы можете хранить и вызывать функции-члены класса или функции-члены структуры.

6. Функции с переменным числом аргументов: `std::function` также поддерживает функции с переменным числом аргументов (variadic functions). Вы можете хранить и вызывать такие функции с помощью `std::function`.

7. Функторы и функциональные объекты: `std::function` может использоваться для хранения и вызова функциональных объектов, таких как функторы (functors) или лямбда-функции.

Пример использования `std::function` с функциональным объектом:

```cpp
#include <iostream>
#include <functional>

// Пример функционального объекта
struct Multiply {
  int operator()(int a, int b) const {
    return a * b;
  }
};

int main() {
  std::function<int(int, int)> func;  // Объявление std::function для функций с сигнатурой int(int, int)

  Multiply multiply;  // Создание экземпляра функционального объекта

  func = multiply;  // Присваивание функционального объекта

  int result = func(2, 3);  // Вызов хранимой функции

  std::cout << result << std::endl;  // Вывод результата (6)

  return 0;
}
```

В этом примере `std::function` используется для хранения и вызова функционального объекта `Multiply`. Функциональный объект представляет собой структуру с перегруженным оператором `()`, который позволяет его использовать как функцию.

`std::function` обеспечивает удобный интерфейс для работы с функциями различных типов, что позволяет создавать более гибкий и модульный код. Он часто используется в ситуациях, где требуется передача функций как параметров или их хранение в коллекциях, а также при работе с колбэками и обработчиками событий.

[observable](./code/observable.cpp)

`constexpr` - это ключевое слово в C++, которое используется для указания компилятору, что выражение или функция может быть вычислена во время компиляции. Оно представляет собой часть расширения константного выражения (constexpr) в стандарте C++11.

Основные характеристики и использование `constexpr`:

1. Константные выражения: `constexpr` позволяет определить переменные или функции, которые могут быть вычислены на этапе компиляции. Это означает, что значение переменной или результат функции будет известен на этапе компиляции, а не во время выполнения программы.

Пример использования `constexpr` для определения константной переменной:

```cpp
constexpr int square(int x) {
    return x * x;
}

int main() {
    constexpr int size = square(5); // Вычисление на этапе компиляции
    return 0;
}
```

2. Константные функции: `constexpr` также может быть применено к функциям, чтобы указать, что они могут быть вызваны в константном контексте и вернуть результат на этапе компиляции.

Пример использования `constexpr` для определения константной функции:

```cpp
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    constexpr int result = factorial(5); // Вычисление на этапе компиляции
    return 0;
}
```

3. Константные объекты: `constexpr` также может быть использовано для определения константных объектов, т.е. объектов, чье значение известно на этапе компиляции и не может быть изменено во время выполнения программы.

Пример использования `constexpr` для определения константного объекта:

```cpp
constexpr int size = 10;
```

Важно отметить, что `constexpr` может быть использовано только для выражений и функций, которые могут быть вычислены на этапе компиляции. Компилятор проверяет, что все операции и функции, использованные в `constexpr`, также являются константными и могут быть вычислены на этапе компиляции.

Использование `constexpr` позволяет программисту создавать более эффективный код, так как некоторые операции могут быть выполнены на этапе компиляции, а не во время выполнения программы. Кроме того, это может помочь обеспечить более строгую типизацию и уменьшить возможность ошибок во время выполнения.

Вот пример использования `constexpr` для определения константной функции и переменной:

```cpp
#include <iostream>

constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    constexpr int result = factorial(5); // Вычисление на этапе компиляции
    std::cout << "Factorial of 5 is: " << result << std::endl;
    return 0;
}
```

В этом примере функция `factorial` определена с использованием `constexpr`, что означает, что она может быть вычислена на этапе компиляции, если значение аргумента известно на этапе компиляции. В функции используется рекурсивный подход для вычисления факториала числа.

В функции `main` мы объявляем переменную `result` с помощью `constexpr` и вызываем функцию `factorial(5)`. Так как значение 5 известно на этапе компиляции, компилятор вычислит значение факториала и присвоит его переменной `result`. Затем мы выводим значение `result` на экран.

Поскольку вычисление факториала происходит на этапе компиляции, мы получим следующий вывод:

```
Factorial of 5 is: 120
```

Это демонстрирует, как `constexpr` позволяет выполнить вычисления на этапе компиляции, что может привести к оптимизации и повышению производительности программы.

## Links
[CPP11](https://en.cppreference.com/w/cpp/11)

Вот несколько полезных ресурсов для изучения C++11:

1. cppreference.com: Это онлайн-справочник по языку C++ и его стандартам, включая C++11. Здесь вы найдете подробную документацию о новых функциях, ключевых словах и других изменениях в C++11: https://en.cppreference.com/w/cpp/11

2. "Effective Modern C++" (Scott Meyers): Эта книга предлагает практические советы и рекомендации по использованию современных функций C++, включая C++11. Она поможет вам изучить и применить новые возможности языка: https://www.oreilly.com/library/view/effective-modern-c/9781491908419/

3. "C++ Primer, 5th Edition" (Stanley B. Lippman, Josée Lajoie, Barbara E. Moo): Эта книга является введением в C++ и включает обновленные материалы по C++11. Она предлагает подробные объяснения и множество примеров кода: https://www.oreilly.com/library/view/c-primer-fifth/9780133053043/

4. Официальная документация компиляторов: Если вы используете конкретный компилятор C++ (например, GCC или Clang), официальная документация компилятора может содержать подробные сведения о поддержке C++11 и специфических функциях.

5. Проекты с открытым исходным кодом: Изучение проектов с открытым исходным кодом, которые используют C++11, может помочь вам увидеть реальные примеры его применения и лучшие практики. Некоторые известные проекты, такие как Boost, Google Chrome и LLVM, активно используют C++11.
