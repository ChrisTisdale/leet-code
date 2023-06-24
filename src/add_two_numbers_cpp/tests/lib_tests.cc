#include <gtest/gtest.h>
#include "../src/Solution.h"
#include "../src/ListNode.h"

ListNode* to_list_node(const int input) {
    const auto val = input % 10;
    const auto next = input / 10;
    return new ListNode(val, next != 0 ? to_list_node(next) : nullptr);
}

TEST(ADD_TWO_NUMBERS, Example1Test) {
    Solution sl;
    auto expected = to_list_node(807);
    auto result = sl.addTwoNumbers(to_list_node(342), to_list_node(465));
    GTEST_ASSERT_TRUE(result);
    while (result && expected) {
        GTEST_ASSERT_EQ(expected->val, result->val);
        expected = expected->next;
        result = result->next;
    }

    GTEST_ASSERT_FALSE(result || expected);
}

TEST(ADD_TWO_NUMBERS, Example2Test) {
    Solution sl;
    auto expected = to_list_node(0);
    auto result = sl.addTwoNumbers(to_list_node(0), to_list_node(0));
    GTEST_ASSERT_TRUE(result);
    while (result && expected) {
        GTEST_ASSERT_EQ(expected->val, result->val);
        expected = expected->next;
        result = result->next;
    }

    GTEST_ASSERT_FALSE(result || expected);
}

TEST(ADD_TWO_NUMBERS, Example3Test) {
    Solution sl;
    auto expected = to_list_node(10009998);
    auto result = sl.addTwoNumbers(to_list_node(9999999), to_list_node(9999));
    GTEST_ASSERT_TRUE(result);
    while (result && expected) {
        GTEST_ASSERT_EQ(expected->val, result->val);
        expected = expected->next;
        result = result->next;
    }

    GTEST_ASSERT_FALSE(result || expected);
}

TEST(ADD_TWO_NUMBERS, Example4Test) {
    Solution sl;
    auto expected = to_list_node(10000000);
    auto result = sl.addTwoNumbers(to_list_node(1), to_list_node(9999999));
    GTEST_ASSERT_TRUE(result);
    while (result && expected) {
        GTEST_ASSERT_EQ(expected->val, result->val);
        expected = expected->next;
        result = result->next;
    }

    GTEST_ASSERT_FALSE(result || expected);
}
