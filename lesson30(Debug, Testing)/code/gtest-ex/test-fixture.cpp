#include <gtest/gtest.h>
#include <iostream>

// Тестовый класс
class MyTestSuite : public ::testing::Test {
protected:
    void utiliies() {
        // prepare environment
        std::cout << "Prepare some data" << std::endl;
        EXPECT_TRUE(true);
    }

    void SetUp() override   {
        std::cout << "SetUp" << std::endl;
        // create test random files
        // Настройка состояния перед каждым тестом
    }

    void TearDown() override {
        std::cout << "TearDown" << std::endl;
        // Очистка после каждого теста
    }
};

// Тестовый метод
TEST_F(MyTestSuite, Test1) {
    utiliies();
    std::cout << "Start test1" << std::endl;
    // Код проверки
    ASSERT_EQ(2 + 2, 4);
    EXPECT_TRUE(true);
}

TEST_F(MyTestSuite, Test2) {
    std::cout << "Start test2" << std::endl;
    // Код проверки
    ASSERT_NE(2 + 2, 5);
    EXPECT_TRUE(true);
}