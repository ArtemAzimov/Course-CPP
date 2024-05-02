#include <gtest/gtest.h>

// Тестовый класс
class MyTestSuite : public ::testing::Test {
protected:
    void SetUp() override {
        // Настройка состояния перед каждым тестом
    }

    void TearDown() override {
        // Очистка после каждого теста
    }
};

// Тестовый метод
TEST_F(MyTestSuite, TestName) {
    // Код проверки
    ASSERT_EQ(2 + 2, 4);
    EXPECT_TRUE(true);
}