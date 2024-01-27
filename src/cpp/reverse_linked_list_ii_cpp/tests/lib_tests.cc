#include <gtest/gtest.h>
#include "../src/Solution.h"

TEST(REVERSE_LINKED_II_LIST, Example1Test) {
    Solution sl;
    const std::vector expected = {1, 4, 3, 2, 5};
    const std::vector input = {1, 2, 3, 4, 5};
    const auto head = ListNode::fromVector(input);
    const auto result = sl.reverseBetween(head, 2, 4);
    const auto resultList = result->toList();
    GTEST_ASSERT_EQ(expected.size(), resultList.size());
    for (std::size_t i = 0; i < expected.size(); ++i) {
        GTEST_ASSERT_EQ(expected[i], resultList[i]);
    }

    delete head;
}

TEST(REVERSE_LINKED_II_LIST, Example2Test) {
    Solution sl;
    const std::vector expected = {5};
    const std::vector input = {5};
    const auto head = ListNode::fromVector(input);
    const auto result = sl.reverseBetween(head, 1, 1);
    const auto resultList = result->toList();
    GTEST_ASSERT_EQ(expected.size(), resultList.size());
    for (std::size_t i = 0; i < expected.size(); ++i) {
        GTEST_ASSERT_EQ(expected[i], resultList[i]);
    }

    delete head;
}

TEST(REVERSE_LINKED_II_LIST, Example3Test) {
    Solution sl;
    const std::vector expected = {5, 6};
    const std::vector input = {6, 5};
    const auto head = ListNode::fromVector(input);
    const auto result = sl.reverseBetween(head, 1, 2);
    const auto resultList = result->toList();
    GTEST_ASSERT_EQ(expected.size(), resultList.size());
    for (std::size_t i = 0; i < expected.size(); ++i) {
        GTEST_ASSERT_EQ(expected[i], resultList[i]);
    }

    delete head;
}

TEST(REVERSE_LINKED_II_LIST, Example4Test) {
    Solution sl;
    const std::vector expected = {6, 5, 1, 2, 3, 8, 9};
    const std::vector input = {6, 5, 3, 2, 1, 8, 9};
    const auto head = ListNode::fromVector(input);
    const auto result = sl.reverseBetween(head, 3, 5);
    const auto resultList = result->toList();
    GTEST_ASSERT_EQ(expected.size(), resultList.size());
    for (std::size_t i = 0; i < expected.size(); ++i) {
        GTEST_ASSERT_EQ(expected[i], resultList[i]);
    }

    delete head;
}
