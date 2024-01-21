#include <gtest/gtest.h>
#include <set>
#include "../src/Solution.h"

static void check_results(const std::set<std::string>&expected, const std::vector<std::string>&result) {
    GTEST_ASSERT_EQ(expected.size(), result.size());
    for (const auto&c: expected) {
        const auto found = std::find(result.begin(), result.end(), c);
        GTEST_ASSERT_NE(found, result.end());
    }
}

TEST(GENERATE_PARENTHESES, Example1Test) {
    Solution s;
    const auto result = s.generateParenthesis(1);
    GTEST_ASSERT_EQ(1, result.size());
    const auto&value = result[0];
    GTEST_ASSERT_EQ("()", value);
}

TEST(GENERATE_PARENTHESES, Example2Test) {
    const std::set<std::string> expected = {"()()", "(())"};
    Solution s;
    const auto result = s.generateParenthesis(2);
    check_results(expected, result);
}

TEST(GENERATE_PARENTHESES, Example3Test) {
    const std::set<std::string> expected = {"()()()", "(())()", "(()())", "((()))", "()(())"};
    Solution s;
    const auto result = s.generateParenthesis(3);
    check_results(expected, result);
}

TEST(GENERATE_PARENTHESES, Example4Test) {
    const std::set<std::string> expected = {
        "()()()()", "()(())()", "()(()())", "()((()))", "()()(())", "(()()())", "((())())", "((()()))", "(((())))",
        "(()(()))", "(())(())", "(())()()", "((()))()", "(()())()"
    };
    Solution s;
    const auto result = s.generateParenthesis(4);
    check_results(expected, result);
}

TEST(GENERATE_PARENTHESES, Example5Test) {
    const std::set<std::string> expected = {
        "()()()()()", "()()(())()", "()()(()())", "()()((()))", "()()()(())", "()(()()())", "()((())())", "()((()()))",
        "()(((())))", "()(()(()))", "()(())(())", "()(())()()", "()((()))()", "()(()())()",
        "(()()()())", "(()(())())", "(()(()()))", "(()((())))", "(()()(()))", "((()()()))", "(((())()))", "(((()())))",
        "((((()))))","((()(())))", "((())(()))", "((())()())", "(((()))())", "((()())())",
        "(()()())()", "((())())()", "((()()))()", "(((())))()", "(()(()))()",
        "(()())()()", "((()))()()", "(()())(())", "((()))(())",
        "(())()()()", "(())(())()", "(())(()())", "(())((()))", "(())()(())"
    };
    Solution s;
    const auto result = s.generateParenthesis(5);
    check_results(expected, result);
}
