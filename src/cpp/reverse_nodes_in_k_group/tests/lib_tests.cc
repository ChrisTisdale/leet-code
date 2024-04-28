#include <gtest/gtest.h>
#include "../src/Solution.h"

TEST(REVERSE_NODES_IN_K_GROUP, Example1Test) {
    Solution sl;
    const std::vector expected = {2, 1, 4, 3, 5};
    const std::vector input = {1, 2, 3, 4, 5};
    const auto head = ListNode::fromVector(input);
    const auto result = sl.reverseBetween(head, 2);
    const auto resultList = result->toList();
    GTEST_ASSERT_EQ(expected.size(), resultList.size());
    for (std::size_t i = 0; i < expected.size(); ++i) {
        GTEST_ASSERT_EQ(expected[i], resultList[i]);
    }

    delete head;
}

TEST(REVERSE_NODES_IN_K_GROUP, Example2Test) {
    Solution sl;
    const std::vector expected = {3, 2, 1, 4, 5};
    const std::vector input = {1, 2, 3, 4, 5};
    const auto head = ListNode::fromVector(input);
    const auto result = sl.reverseBetween(head, 3);
    const auto resultList = result->toList();
    GTEST_ASSERT_EQ(expected.size(), resultList.size());
    for (std::size_t i = 0; i < expected.size(); ++i) {
        GTEST_ASSERT_EQ(expected[i], resultList[i]);
    }

    delete head;
}
