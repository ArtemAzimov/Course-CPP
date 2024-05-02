#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "mock.hpp"

using ::testing::_;


// Тестовый случай с использованием мок-объекта
TEST(MyClassTest, PerformOperationTest) {
    // Создаем мок-объект зависимости
    MockDependency mockDependency;

    // Устанавливаем ожидание вызова метода GetValue() и задаем возвращаемое значение
    EXPECT_CALL(mockDependency, GetValue(_))
        .WillOnce(::testing::Return(10));

    // Создаем объект тестируемого класса с мок-объектом в качестве зависимости
    MyClass myClass(&mockDependency);

    // Вызываем метод PerformOperation() на объекте myClass
    int result = myClass.PerformOperation();

    // Проверяем, что результат соответствует ожидаемому значению (10 * 2 = 20)
    ASSERT_EQ(result, 20);
}