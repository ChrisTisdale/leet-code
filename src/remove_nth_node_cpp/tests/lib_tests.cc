#include <gtest/gtest.h>
#include "../src/Solution.h"
#include "../src/ListNode.h"

TEST(REMOVE_NTH_NODE, Example1Test) {
    Solution sl;
    std::vector<int> expected = { 1, 2, 3, 5 };
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    auto result = sl.removeNthFromEnd(head, 2);
    GTEST_ASSERT_NE(nullptr, result);
    auto resultList = result->toList();
    GTEST_ASSERT_EQ(expected.size(), resultList.size());

    for (int i = 0; i < expected.size(); ++i) {
        GTEST_ASSERT_EQ(expected[i], resultList[i]);
    }

    auto current = head;
    while (current) {
        head = head->next;
        delete current;
        current = head;
    }
}

TEST(REMOVE_NTH_NODE, Example2Test) {
    Solution sl;
    ListNode* head = new ListNode(1);
    auto result = sl.removeNthFromEnd(head, 1);
    GTEST_ASSERT_EQ(nullptr, result);
    auto current = head;
    while (current) {
        head = head->next;
        delete current;
        current = head;
    }
}

TEST(REMOVE_NTH_NODE, Example3Test) {
    Solution sl;
    std::vector<int> expected = { 1 };
    ListNode* head = new ListNode(1, new ListNode(2));
    auto result = sl.removeNthFromEnd(head, 1);
    GTEST_ASSERT_NE(nullptr, result);
    auto resultList = result->toList();
    GTEST_ASSERT_EQ(expected.size(), resultList.size());

    for (int i = 0; i < expected.size(); ++i) {
        GTEST_ASSERT_EQ(expected[i], resultList[i]);
    }

    auto current = head;
    while (current) {
        head = head->next;
        delete current;
        current = head;
    }
}
