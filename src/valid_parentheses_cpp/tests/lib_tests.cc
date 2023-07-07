#include <gtest/gtest.h>
#include "../src/Solution.h"

TEST(VALID_PARENTHESES, Example1Test) {
    Solution sl;
    GTEST_ASSERT_TRUE(sl.isValid("()"));
}

TEST(VALID_PARENTHESES, Example2Test) {
    Solution sl;
    GTEST_ASSERT_TRUE(sl.isValid("()[]{}"));
}

TEST(VALID_PARENTHESES, Example3Test) {
    Solution sl;
    GTEST_ASSERT_FALSE(sl.isValid("(]"));
}

TEST(VALID_PARENTHESES, Example4Test) {
    Solution sl;
    GTEST_ASSERT_FALSE(sl.isValid("]"));
}
