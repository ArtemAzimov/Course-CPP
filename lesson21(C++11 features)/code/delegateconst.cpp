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

int main()
{

  // Пример использования делегирующего конструктора
  Point p1;        // Используется конструктор Point()
  Point p2(5, 10); // Используется конструктор Point(int x, int y)

  Rectangle r1;               // Используется конструктор Rectangle()
  Rectangle r2(10, 20, 5, 5); // Используется конструктор Rectangle(int width, int height, int x, int y)
}