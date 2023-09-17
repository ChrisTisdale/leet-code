#include <gtest/gtest.h>
#include "../src/Solution.h"

TEST(PAIRS_SPELLS_POTIONS, Example1Test) {
    Solution sl;
    std::vector<int> spells = { 5, 1, 3 };
    std::vector<int> potions = { 1, 2, 3, 4, 5 };
    auto result = sl.successfulPairs(spells, potions, 7);
    GTEST_ASSERT_EQ(3, result.size());
    GTEST_ASSERT_EQ(4, result[0]);
    GTEST_ASSERT_EQ(0, result[1]);
    GTEST_ASSERT_EQ(3, result[2]);
}

TEST(PAIRS_SPELLS_POTIONS, Example2Test) {
    Solution sl;
    std::vector<int> spells = { 3, 1, 2 };
    std::vector<int> potions = { 8, 5, 8 };
    auto result = sl.successfulPairs(spells, potions, 16);
    GTEST_ASSERT_EQ(3, result.size());
    GTEST_ASSERT_EQ(2, result[0]);
    GTEST_ASSERT_EQ(0, result[1]);
    GTEST_ASSERT_EQ(2, result[2]);
}

TEST(PAIRS_SPELLS_POTIONS, Example3Test) {
    Solution sl;
    std::vector<int> spells = { 85899345, 42949672, 21474836 };
    std::vector<int> potions = { 52, 104, 205 };
    auto result = sl.successfulPairs(spells, potions, 4294967296);
    GTEST_ASSERT_EQ(3, result.size());
    GTEST_ASSERT_EQ(3, result[0]);
    GTEST_ASSERT_EQ(2, result[1]);
    GTEST_ASSERT_EQ(1, result[2]);
}
