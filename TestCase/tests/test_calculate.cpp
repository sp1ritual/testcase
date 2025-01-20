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
TEST(CalculateANDreturnTest,OnlyDigits){
    EXPECT_EQ(calulcateANDreturn("123"),6);
}
TEST(CalculateANDreturnTest,MixedDigits){
    EXPECT_EQ(calulcateANDreturn("1a2v3b4"),10);
}
TEST(CalculateANDreturnTest, EmptyString){
    EXPECT_EQ(calulcateANDreturn(""),0);
}
TEST(CalculateANDreturnTest, OnlyZero){
    EXPECT_EQ(calulcateANDreturn("000"),0);
}
TEST(countOfsymbolsTest,LessOne){
    EXPECT_EQ(countOfsymbols("1"),false);
}
TEST(countOfsymbolsTest,Multiple){
    EXPECT_EQ(countOfsymbols("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"),true);
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}