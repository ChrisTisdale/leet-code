#include <gtest/gtest.h>
#include <vector>
#include "../src/Solution.h"

TEST(FIND_THE_DUPLICATE_NUMBER, Example1Test) {
    std::vector<int> input{1, 3, 4, 2, 2};
    Solution sl;
    auto result = sl.findDuplicate(input);
    GTEST_ASSERT_EQ(2, result);
}

TEST(FIND_THE_DUPLICATE_NUMBER, Example2Test) {
    std::vector<int> input{3, 1, 3, 4, 2};
    Solution sl;
    auto result = sl.findDuplicate(input);
    GTEST_ASSERT_EQ(3, result);
}
