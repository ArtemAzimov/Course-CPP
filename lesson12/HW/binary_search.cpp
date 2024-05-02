#include <iostream>

using std::cout;
using std::endl;

void bubble_sort(int* array, unsigned size)
{
    for (int i = 0; i < size - 1; i++)  // пока кол-во проходов < размер - 1 (последний и так окажется в конце)
    {
        for (int j = 0; j < size - i - 1; j++)  // пока элемент < размер - кол-во проходов - 1 (последний элемент)
        {
            if (array[j] > array[j + 1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int binary_search(int* array, unsigned size, int value)
{
    int counter = size / 2;         // максимальное число итераций
    int index = (size - 1) / 2;     // первая (стартовая) медиум точка
    cout << "......Current index state is: " << index << endl;
    while (counter != 0)
    {
        if (value == array[index])
            return index;

        if (value < array[index])
        {
            index = index / 2;      // половинит "левую" часть
            cout << "......Current index state is: " << index << endl;
            counter--;
        }
        
        else if (value > array[index])
        {
            if (counter == 1)    // костыль если value это последний элемент массива, иначе делится непрально  ¯\_(ツ)_/¯
                index = ((index + size) / 2);   
            else
            {
                index = ((index + (size - 1)) / 2);   // накидывает среднее из "верхнего" остатка, по умолчанию int округляет влево
                cout << "......Current index state is: " << index << endl;
                counter--;
            }
        }
    }
    return -1;  // если ни одно условие цикла не сработало (числа нет в масиве), выдает -1, main принимает и выводит соотв. текст
}

void show(int* array, unsigned size)
{
    for (int i = 0; i != size; i++)
    {
        cout << array[i] << '\t';
    }
    cout << endl;
}

int main()
{
    // int array[6] = {10, 2, 6, 12, 4, 8};
    int array[20] = {10, 2, 6, 12, 4, 8, 34, 328, 91, 398, 93, 38, 83, 182, 273, 82, 11203, 929, 73, 15};

    show(array, 20);

    bubble_sort(array, 20);
    show(array, 20);

    int index = binary_search(array, 20, 11203);

    if (index == -1) cout << "There is no such value" << endl;      // еррор: такого числа нет
    else cout << "Your value is found at index: " << index << endl;

/*
   {2, 4, 6, 8, 10, 12}
    0  1  2  3   4   5

   case #1 (value = 4)      -> size / 2 (5 / 2) = 2 (value 6)
    0  1  [2] 3  4   5      -> index / 2 (2 / 2) = 1 (value 4)
    0 [1]  2  3  4   5      -> !value is found!

   case #2 (value = 10)
    0  1  [2]  3  4  5      -> size / 2 (5 / 2) = 2 (value 6)
    0  1   2  [3] 4  5      -> (index + (size - 1)) / 2 (2 + (6 - 1) / 2) = 3 (value 8)
    0  1   2   3 [4] 5      -> (3+5) / 2 = 4 (value 10)
    0  1   2   3  4 [5]     -> (4+5) / 2 = 4 (value 10), а должно быть value 12.
                            для всех должен округлять в меньшую, кроме последнего элемента. Мб чтото с чет нечет, надо подумОть
                            чем число ближе к концу тем больше итераций приходится проделывать, типа "уточнение"
*/                                             
}