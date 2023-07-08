#include <gtest/gtest.h>
#include "../src/Solution.h"

TEST(REVERSE_LINKED_LIST, Example1Test) {
    Solution sl;
    std::vector<int> expected = { 5, 4, 3, 2, 1 };
    std::vector<int> input = { 1, 2, 3, 4, 5 };
    auto head = ListNode::fromVector(input);
    auto result = sl.reverseList(head);
    auto resultList = result->toList();
    GTEST_ASSERT_EQ(expected.size(), resultList.size());
    for (std::size_t i = 0; i < expected.size(); ++i) {
        GTEST_ASSERT_EQ(expected[i], resultList[i]);
    }

    delete head;
}

TEST(REVERSE_LINKED_LIST, Example2Test) {
    Solution sl;
    std::vector<int> expected = { 2, 1 };
    std::vector<int> input = { 1, 2 };
    auto head = ListNode::fromVector(input);
    auto result = sl.reverseList(head);
    auto resultList = result->toList();
    GTEST_ASSERT_EQ(expected.size(), resultList.size());
    for (std::size_t i = 0; i < expected.size(); ++i) {
        GTEST_ASSERT_EQ(expected[i], resultList[i]);
    }

    delete head;
}

TEST(REVERSE_LINKED_LIST, Example3Test) {
    Solution sl;
    auto result = sl.reverseList(nullptr);
    GTEST_ASSERT_EQ(nullptr, result);
}
