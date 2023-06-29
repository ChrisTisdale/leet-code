#include <gtest/gtest.h>
#include "../src/Solution.h"

TEST(BINNARY_SEARCH, Example1Test) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string("abcabcbb"));
    GTEST_ASSERT_EQ(3, result);
}

TEST(BINNARY_SEARCH, Example2Test) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string("bbbbb"));
    GTEST_ASSERT_EQ(1, result);
}

TEST(BINNARY_SEARCH, Example3Test) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string("pwwkew"));
    GTEST_ASSERT_EQ(3, result);
}

TEST(BINNARY_SEARCH, Example4Test) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string(" -&${}kj3222"));
    GTEST_ASSERT_EQ(10, result);
}

TEST(BINNARY_SEARCH, Example5Test) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string("  &${}kj3222"));
    GTEST_ASSERT_EQ(9, result);
}

TEST(BINNARY_SEARCH, Example6Test) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string("dvdf"));
    GTEST_ASSERT_EQ(3, result);
}

TEST(BINNARY_SEARCH, CaseDoesntMatterTest) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string("aAaAaAaAaA"));
    GTEST_ASSERT_EQ(2, result);
}

TEST(BINNARY_SEARCH, Example7Test) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string("tmmzuxt"));
    GTEST_ASSERT_EQ(5, result);
}

TEST(BINNARY_SEARCH, AllCharacterAndLettersTest) {
    Solution sl;
    auto result = sl.lengthOfLongestSubstring(std::string("asdfghjkl;'qwertyuiop[]\\zxcvbnm,./1234567890-=!@#$%^&*()_+ASDFGHJKLQWERTYUIOPZXCVBNM"));
    GTEST_ASSERT_EQ(84, result);
}