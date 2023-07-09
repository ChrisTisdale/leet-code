#include <gtest/gtest.h>
#include <algorithm>
#include "../src/Solution.h"

TEST(TWO_SUM, Example1Test) {
    Solution sl;
    std::vector<int> expected = { 0, 1 };
    std::vector<int> input = { 2, 7, 11, 15 };
    auto result = sl.twoSum(input, 9);
    GTEST_ASSERT_EQ(expected.size(), result.size());
    for (auto r : result) {
        GTEST_ASSERT_NE(expected.end(), std::find(expected.begin(), expected.end(), r));
    }
}

TEST(TWO_SUM, Example2Test) {
    Solution sl;
    std::vector<int> expected = { 1, 2 };
    std::vector<int> input = { 3, 2, 4 };
    auto result = sl.twoSum(input, 6);
    GTEST_ASSERT_EQ(expected.size(), result.size());
    for (auto r : result) {
        GTEST_ASSERT_NE(expected.end(), std::find(expected.begin(), expected.end(), r));
    }
}

TEST(TWO_SUM, Example3Test) {
    Solution sl;
    std::vector<int> expected = { 0, 1 };
    std::vector<int> input = { 3, 3 };
    auto result = sl.twoSum(input, 6);
    GTEST_ASSERT_EQ(expected.size(), result.size());
    for (auto r : result) {
        GTEST_ASSERT_NE(expected.end(), std::find(expected.begin(), expected.end(), r));
    }
}
