#include <gtest/gtest.h>
#include "../src/Solution.h"

TEST(ROAMAN_TO_INT, Example1Test) {
    Solution sl;
    auto result = sl.romanToInt(std::string("III"));
    GTEST_ASSERT_EQ(3, result);
}

TEST(ROAMAN_TO_INT, Example2Test) {
    Solution sl;
    auto result = sl.romanToInt(std::string("LVIII"));
    GTEST_ASSERT_EQ(58, result);
}

TEST(ROAMAN_TO_INT, Example3Test) {
    Solution sl;
    auto result = sl.romanToInt(std::string("MCMXCIV"));
    GTEST_ASSERT_EQ(1994, result);
}

TEST(ROAMAN_TO_INT, Example4Test) {
    Solution sl;
    auto result = sl.romanToInt(std::string("XX"));
    GTEST_ASSERT_EQ(20, result);
}
