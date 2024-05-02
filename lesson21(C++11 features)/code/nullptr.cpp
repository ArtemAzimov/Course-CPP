int main()
{
  int *ptr = nullptr; // Инициализация указателя нулевым значением

  if (ptr == nullptr)
  {
    // Проверка на нулевой указатель
    // ...
  }

}

void foo(int *ptr)
{
  if (ptr == nullptr)
  {
    // Обработка нулевого указателя
    // ...
  }
}