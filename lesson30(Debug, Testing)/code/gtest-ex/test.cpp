#include <gtest/gtest.h>

// Пример тестируемой функции, которую мы хотим протестировать
int Add(int a, int b) {
    return a + b;
}

bool isEmpty(std::vector<int> v) {
    return v.size() == 0;
}

TEST(IsEmpty, Positive) {
    EXPECT_TRUE(isEmpty({1, 2, 3}));
    EXPECT_FALSE(isEmpty({}));

    // ASSERT_TRUE(isEmpty({1, 2, 3}));
    // ASSERT_FALSE(isEmpty({}));
}

// Пример модульного теста для функции Add
TEST(AddTest, PositiveNumbers) {
    // Проверяем, что функция Add возвращает правильную сумму для положительных чисел
    int result = Add(2, 3);
    EXPECT_EQ(result, 5);
}

TEST(AddTest, NotPositiveNumbers) {
    // Проверяем, что функция Add возвращает правильную сумму для положительных чисел
    int result = Add(3, 3);
    EXPECT_NE(result, 5);
}

TEST(AddTest, NegativeNumbers) {
    // Проверяем, что функция Add возвращает правильную сумму для отрицательных чисел
    int result = Add(-2, -3);
    EXPECT_EQ(result, -5);
}

TEST(AddTest, Zero) {
    // Проверяем, что функция Add возвращает правильную сумму для нулей
    int result = Add(0, 0);
    EXPECT_EQ(result, 0);
}

int main(int argc, char** argv) {
    // Инициализация Google Test
    ::testing::InitGoogleTest(&argc, argv);
    
    // Запуск всех тестов
    return RUN_ALL_TESTS();
}
