#include <gtest/gtest.h>
#include <vector>
#include "../src/Solution.h"

TEST(BINNARY_SEARCH, Example1Test) {
    std::vector<int> input{-1, 0, 3, 5, 9, 12};
    Solution sl;
    auto result = sl.search(input, 9);
    GTEST_ASSERT_EQ(4, result);
}

TEST(BINNARY_SEARCH, Example2Test) {
    std::vector<int> input{-1, 0, 3, 5, 9, 12};
    Solution sl;
    auto result = sl.search(input, 2);
    GTEST_ASSERT_EQ(-1, result);
}

TEST(BINNARY_SEARCH, Example3Test) {
    std::vector<int> input{-1, 0, 3, 5, 9, 12};
    Solution sl;
    auto result = sl.search(input, -1);
    GTEST_ASSERT_EQ(0, result);
}

TEST(BINNARY_SEARCH, Example4Test) {
    std::vector<int> input{-1, 0, 3, 5, 9, 12};
    Solution sl;
    auto result = sl.search(input, 12);
    GTEST_ASSERT_EQ(5, result);
}

TEST(BINNARY_SEARCH, Example5Test) {
    std::vector<int> input{2, 5};
    Solution sl;
    auto result = sl.search(input, 0);
    GTEST_ASSERT_EQ(-1, result);
}

TEST(BINNARY_SEARCH, Example6Test) {
    std::vector<int> input{2};
    Solution sl;
    auto result = sl.search(input, 2);
    GTEST_ASSERT_EQ(0, result);
}

TEST(BINNARY_SEARCH, Example7Test) {
    std::vector<int> input;
    Solution sl;
    auto result = sl.search(input, 0);
    GTEST_ASSERT_EQ(-1, result);
}

TEST(BINNARY_SEARCH, Example8Test) {
    std::vector<int> input{5};
    Solution sl;
    auto result = sl.search(input, 0);
    GTEST_ASSERT_EQ(-1, result);
}
