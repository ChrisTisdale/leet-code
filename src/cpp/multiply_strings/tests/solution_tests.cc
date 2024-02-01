#include <gtest/gtest.h>
#include "../src/Solution.h"

TEST(MULTIPLY_STRINGS, Example1Test) {
    const std::string expected = "6";
    Solution sl;
    const auto result = sl.multiply("2", "3");
    GTEST_ASSERT_EQ(expected, result);
}

TEST(MULTIPLY_STRINGS, Example2Test) {
    const std::string expected = "56088";
    Solution sl;
    const auto result = sl.multiply("123", "456");
    GTEST_ASSERT_EQ(expected, result);
}
