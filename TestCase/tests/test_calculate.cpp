#include "calculate.h"

#include <gtest/gtest.h>
#include <sstream>
#include <string>

// Вспомогательная функция для захвата вывода
std::string captureOutput(const std::string& input) {
    Library lib(input);
    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    lib.sorting();
    std::cout.rdbuf(oldCoutBuffer);
    return output.str();
}
TEST(SortingTest, BasicNumeric) {
    Library lib("4321");
    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
    lib.sorting(); // Теперь метод класса
    std::cout.rdbuf(oldCoutBuffer);
    EXPECT_EQ(output.str(), "KB3KB1\n");
}

TEST(SortingTest, EmptyString) {
    Library lib("");
    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
    lib.sorting();
    std::cout.rdbuf(oldCoutBuffer);
    EXPECT_EQ(output.str(), "\n");
}

TEST(CalculateAndReturnTest, OnlyDigits) {
    Library lib("123");
    EXPECT_EQ(lib.calculateAndReturn(), 6);
}

TEST(CalculateAndReturnTest, MixedDigits) {
    Library lib("1a2v3b4");
    EXPECT_EQ(lib.calculateAndReturn(), 10);
}

TEST(CalculateAndReturnTest, EmptyString) {
    Library lib("");
    EXPECT_EQ(lib.calculateAndReturn(), 0);
}

TEST(CalculateAndReturnTest, OnlyZero) {
    Library lib("000");
    EXPECT_EQ(lib.calculateAndReturn(), 0);
}

TEST(CountOfSymbolsTest, LessOne) {
    Library lib("1");
    EXPECT_EQ(lib.countOfSymbols(), false);
}

TEST(CountOfSymbolsTest, Multiple) {
    Library lib("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    EXPECT_EQ(lib.countOfSymbols(), true);
}
