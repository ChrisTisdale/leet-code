#include <gtest/gtest.h>
#include "../src/Solution.h"

TEST(EVALUATE_REVERSE_POLISH_NOTATION, Example1Test) {
    std::vector<std::string> input = {"2","1","+","3","*"};
    constexpr int expected = 9;
    Solution sl;
    const auto result = sl.evalRPN(input);
    GTEST_ASSERT_EQ(expected, result);
}

TEST(EVALUATE_REVERSE_POLISH_NOTATION, Example2Test) {
    std::vector<std::string> input = {"4","13","5","/","+"};
    constexpr int expected = 6;
    Solution sl;
    const auto result = sl.evalRPN(input);
    GTEST_ASSERT_EQ(expected, result);
}

TEST(EVALUATE_REVERSE_POLISH_NOTATION, Example3Test) {
    std::vector<std::string> input = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    constexpr int expected = 22;
    Solution sl;
    const auto result = sl.evalRPN(input);
    GTEST_ASSERT_EQ(expected, result);
}
