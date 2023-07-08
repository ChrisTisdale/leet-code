#include <gtest/gtest.h>
#include "../src/Solution.h"

TEST(LONGEST_SUBSTRING, Example1Test) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string("abcabcbb"));
    GTEST_ASSERT_EQ(3, result);
}

TEST(LONGEST_SUBSTRING, Example2Test) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string("bbbbb"));
    GTEST_ASSERT_EQ(1, result);
}

TEST(LONGEST_SUBSTRING, Example3Test) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string("pwwkew"));
    GTEST_ASSERT_EQ(3, result);
}

TEST(LONGEST_SUBSTRING, Example4Test) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string(" -&${}kj3222"));
    GTEST_ASSERT_EQ(10, result);
}

TEST(LONGEST_SUBSTRING, Example5Test) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string("  &${}kj3222"));
    GTEST_ASSERT_EQ(9, result);
}

TEST(LONGEST_SUBSTRING, Example6Test) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string("dvdf"));
    GTEST_ASSERT_EQ(3, result);
}

TEST(LONGEST_SUBSTRING, CaseDoesntMatterTest) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string("aAaAaAaAaA"));
    GTEST_ASSERT_EQ(2, result);
}

TEST(LONGEST_SUBSTRING, Example7Test) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string("tmmzuxt"));
    GTEST_ASSERT_EQ(5, result);
}

TEST(LONGEST_SUBSTRING, AllCharacterAndLettersTest) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string("asdfghjkl;'qwertyuiop[]\\zxcvbnm,./1234567890-=!@#$%^&*()_+ASDFGHJKLQWERTYUIOPZXCVBNM"));
    GTEST_ASSERT_EQ(84, result);
}