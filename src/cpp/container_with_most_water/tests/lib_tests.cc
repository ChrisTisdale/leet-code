#include <gtest/gtest.h>
#include "../src/Solution.h"

TEST(CONTAINER_WITH_MOST_WATER, Example1Test) {
    std::vector<int> input = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution sl;
    GTEST_ASSERT_EQ(49, sl.maxArea(input));
}

TEST(CONTAINER_WITH_MOST_WATER, Example2Test) {
    std::vector<int> input = {1, 1};
    Solution sl;
    GTEST_ASSERT_EQ(1, sl.maxArea(input));
}
