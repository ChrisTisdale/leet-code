#include <gtest/gtest.h>
#include "../src/Solution.h"

TEST(MERGE_K_SORTED_LISTS, Example1Test) {
    const std::vector expected = {1, 1, 2, 3, 4, 4, 5, 6};
    std::vector lists = {
        ListNode::fromVector({1, 4, 5}), ListNode::fromVector({1, 3, 4}), ListNode::fromVector({2, 6})
    };

    const auto head = Solution::mergeKLists(lists);
    GTEST_ASSERT_NE(nullptr, head);
    const auto result = head->toList();
    GTEST_ASSERT_EQ(expected.size(), result.size());
    for (size_t i = 0; i < expected.size(); ++i) {
        GTEST_ASSERT_EQ(expected[i], result[i]);
    }
}

TEST(MERGE_K_SORTED_LISTS, Example2Test) {
    std::vector<ListNode *> lists = {};
    const auto head = Solution::mergeKLists(lists);
    GTEST_ASSERT_EQ(nullptr, head);
}

TEST(MERGE_K_SORTED_LISTS, Example3Test) {
    std::vector lists = {ListNode::fromVector({})};
    const auto head = Solution::mergeKLists(lists);
    GTEST_ASSERT_EQ(nullptr, head);
}
