#include <gtest/gtest.h>
#include <gmock/gmock.h>

// Функция, которую будем тестировать
int Multiply(int a, int b) {
    return a * b;
}

// Параметризованный тест
class MultiplyTest : public ::testing::TestWithParam<std::tuple<int, int, int>> {};

// Использование параметров теста
TEST_P(MultiplyTest, TestMultiplication) {
    int a, b, expected;
    std::tie(a, b, expected) = GetParam();

    int result = Multiply(a, b);

    ASSERT_EQ(result, expected);
}

// Определение значений параметров теста
INSTANTIATE_TEST_SUITE_P(ParamValues, MultiplyTest, ::testing::Values(
    std::make_tuple(2, 3, 6),
    std::make_tuple(4, 5, 20),
    std::make_tuple(-2, 2, -4)
));