#include "calculate.h"
#include <gtest/gtest.h>
#include <sstream>
#include <string>

// Вспомогательная функция для захвата вывода
std::string captureOutput(const std::string& input) {
    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    sorting(input);

    std::cout.rdbuf(oldCoutBuffer);
    return output.str();
}

// Тесты
TEST(SortingTest, BasicNumeric) {
    EXPECT_EQ(captureOutput("4321"), "KB3KB1");
}

TEST(SortingTest, EmptyString) {
    EXPECT_EQ(captureOutput(""), "");
}

