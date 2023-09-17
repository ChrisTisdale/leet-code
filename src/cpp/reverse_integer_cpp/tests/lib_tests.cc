#include <gtest/gtest.h>
#include "../src/Solution.h"

TEST(REVERSE_INTEGER, Example1Test) {
    Solution sl;
    auto result = sl.reverse(123);
    GTEST_ASSERT_EQ(321, result);
}

TEST(REVERSE_INTEGER, Example2Test) {
    Solution sl;
    auto result = sl.reverse(-123);
    GTEST_ASSERT_EQ(-321, result);
}

TEST(REVERSE_INTEGER, Example3Test) {
    Solution sl;
    auto result = sl.reverse(120);
    GTEST_ASSERT_EQ(21, result);
}

TEST(REVERSE_INTEGER, ZeroTest) {
    Solution sl;
    auto result = sl.reverse(0);
    GTEST_ASSERT_EQ(0, result);
}

TEST(REVERSE_INTEGER, LargeNumberTest) {
    Solution sl;
    auto result = sl.reverse(1234567890);
    GTEST_ASSERT_EQ(987654321, result);
}

TEST(REVERSE_INTEGER, MultipleZerosTest) {
    Solution sl;
    auto result = sl.reverse(1230000000);
    GTEST_ASSERT_EQ(321, result);
}

TEST(REVERSE_INTEGER, OverflowTest) {
    Solution sl;
    auto result = sl.reverse(1534236496);
    GTEST_ASSERT_EQ(0, result);
}
