#include <vector>

class MyVeryLongNameClassVeryVery {
    public: 
    
};

MyVeryLongNameClassVeryVery init()
{
        return MyVeryLongNameClassVeryVery();
}

int main()
{
    auto container = std::vector<int>();
    auto pUniq = std::make_shared<int>();
    auto myClass = init();

    auto x = 10;                 // Компилятор автоматически определит тип x как int.
    auto name = "John";          // Компилятор автоматически определит тип name как const char*.
    auto it = container.begin(); // Компилятор автоматически определит тип it как итератор контейнера.
}