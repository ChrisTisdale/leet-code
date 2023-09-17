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
    auto left = to_list_node(342);
    auto right = to_list_node(465);
    auto result = sl.addTwoNumbers(left, right);
    GTEST_ASSERT_TRUE(result);
    while (result && expected) {
        GTEST_ASSERT_EQ(expected->val, result->val);
        expected = expected->next;
        result = result->next;
    }

    GTEST_ASSERT_FALSE(result || expected);
    delete expected;
    delete left;
    delete right;
}

TEST(ADD_TWO_NUMBERS, Example2Test) {
    Solution sl;
    auto expected = to_list_node(0);
    auto left = to_list_node(0);
    auto right = to_list_node(0);
    auto result = sl.addTwoNumbers(left, right);
    GTEST_ASSERT_TRUE(result);
    while (result && expected) {
        GTEST_ASSERT_EQ(expected->val, result->val);
        expected = expected->next;
        result = result->next;
    }

    GTEST_ASSERT_FALSE(result || expected);
    delete expected;
    delete left;
    delete right;
}

TEST(ADD_TWO_NUMBERS, Example3Test) {
    Solution sl;
    auto expected = to_list_node(10009998);
    auto left = to_list_node(9999999);
    auto right = to_list_node(9999);
    auto result = sl.addTwoNumbers(left, right);
    GTEST_ASSERT_TRUE(result);
    while (result && expected) {
        GTEST_ASSERT_EQ(expected->val, result->val);
        expected = expected->next;
        result = result->next;
    }

    GTEST_ASSERT_FALSE(result || expected);
    delete expected;
    delete left;
    delete right;
}

TEST(ADD_TWO_NUMBERS, Example4Test) {
    Solution sl;
    auto expected = to_list_node(10000000);
    auto left = to_list_node(1);
    auto right = to_list_node(9999999);
    auto result = sl.addTwoNumbers(left, right);
    GTEST_ASSERT_TRUE(result);
    while (result && expected) {
        GTEST_ASSERT_EQ(expected->val, result->val);
        expected = expected->next;
        result = result->next;
    }

    GTEST_ASSERT_FALSE(result || expected);
    delete expected;
    delete left;
    delete right;
}
