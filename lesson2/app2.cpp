#include <iostream>

using namespace std;

int main()
{
    //int a = 2;
    //int rez = 0;

    //int rez = (a % 2 == 0) ? a : a * (-1);

    //switch (a) { // Выполняет и идет дальше если верно
    //case 0: cout << "0";
    //    break;
    //case 1: cout << "1";
    //case 2: cout << "2";
    //default:
    //    cout << "default";
    //}

    //int b = 0;
    //cout << ">: ";
    //cin >> b;

    //switch (b) {
    //case 1: cout << "nothing";
    //    break;
    //case 2: cout << "third place";
    //    break;
    //case 3: cout << "second place";
    //    break;
    //case 4: cout << "first place";
    //    break;
    //default:
    //    cout << "empty";
    //}

    //int a = 0;
    //a++; // Инкрементирование
    //a--; // Декрементирование

    /*
    int a0 = 0;
    int a1 = 0;
    int a2 = 0;
    int a3 = 0;
    int i = 0;

    cout << ">: ";
    cin >> a0;
    cin >> a1;
    cin >> a2;
    cin >> a3;
    if (a0 % 8 == 0) {
        i++;
    }
    if (a1 % 8 == 0) {
        i++;
    }
    if (a2 % 8 == 0) {
        i++;
    }
    if (a3 % 8 == 0) {
        i++;
    }

    if (i > 0) {
        cout << i;
    }
    else cout << "Not found";

    int x = 1;
    int y = 1;

    cout << x++; // Возвращение -> прибавление - ! выводит x, скрыто меняет значение в ячейки памяти Х
    // постфиксная инкрементация
    cout << ++y; // Прибавление -> возврат
    // префиксная инкрементация

    cout << (x++ + ++y); // 5

    int counter = 0;

    while (counter <= 100) { // Цикл "пока" | Цикл с предусловием
        cout << "counter = " << counter << "/n";
        counter++;
    }

    do { // Цикл с постусловием
        cout << "counter = " << counter << "/n";
        counter++;
    } while (counter <= 100);

    for (int counter = 0; counter <= 100; counter++) { // Цикл "Для" 
        cout << "counter = " << counter << "/n";
    } */

    int x = 100;
    int& _x = x; // Переменная ссылочного типа &

    cout << ">: " << x;
    _x = 50;
    cout << ">: " << x;
}

