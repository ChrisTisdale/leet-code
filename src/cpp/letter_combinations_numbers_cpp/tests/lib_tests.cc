#include <gtest/gtest.h>
#include <algorithm>
#include "../src/Solution.h"

TEST(LETTER_COMBINATIONS_NUMBERS, Example1Test) {
    Solution sl;
    const auto expected = std::vector<std::string>{ "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" };
    auto result = sl.letterCombinations("23");
    GTEST_ASSERT_EQ(expected.size(), result.size());
    for (auto value : expected) {
        GTEST_ASSERT_NE(std::find(result.begin(), result.end(), value), result.end());
    }
}

TEST(LETTER_COMBINATIONS_NUMBERS, Example2Test) {
    Solution sl;
    const auto expected = std::vector<std::string>();
    auto result = sl.letterCombinations("");
    GTEST_ASSERT_EQ(expected.size(), result.size());
}

TEST(LETTER_COMBINATIONS_NUMBERS, Example3Test) {
    Solution sl;
    const auto expected = std::vector<std::string>{ "a", "b", "c" };

    auto result = sl.letterCombinations("2");
    GTEST_ASSERT_EQ(expected.size(), result.size());
    for (auto value : expected) {
        GTEST_ASSERT_NE(std::find(result.begin(), result.end(), value), result.end());
    }
}

TEST(LETTER_COMBINATIONS_NUMBERS, FourNumberTest) {
    Solution sl;
    const auto expected = std::vector<std::string>{
         "agpw", "bgpw", "cgpw", "ahpw", "bhpw", "chpw", "aipw", "bipw", "cipw", "agqw", "bgqw",
         "cgqw", "ahqw", "bhqw", "chqw", "aiqw", "biqw", "ciqw", "agrw", "bgrw", "cgrw", "ahrw",
         "bhrw", "chrw", "airw", "birw", "cirw", "agsw", "bgsw", "cgsw", "ahsw", "bhsw", "chsw",
         "aisw", "bisw", "cisw", "agpx", "bgpx", "cgpx", "ahpx", "bhpx", "chpx", "aipx", "bipx",
         "cipx", "agqx", "bgqx", "cgqx", "ahqx", "bhqx", "chqx", "aiqx", "biqx", "ciqx", "agrx",
         "bgrx", "cgrx", "ahrx", "bhrx", "chrx", "airx", "birx", "cirx", "agsx", "bgsx", "cgsx",
         "ahsx", "bhsx", "chsx", "aisx", "bisx", "cisx", "agpy", "bgpy", "cgpy", "ahpy", "bhpy",
         "chpy", "aipy", "bipy", "cipy", "agqy", "bgqy", "cgqy", "ahqy", "bhqy", "chqy", "aiqy",
         "biqy", "ciqy", "agry", "bgry", "cgry", "ahry", "bhry", "chry", "airy", "biry", "ciry",
         "agsy", "bgsy", "cgsy", "ahsy", "bhsy", "chsy", "aisy", "bisy", "cisy", "agpz", "bgpz",
         "cgpz", "ahpz", "bhpz", "chpz", "aipz", "bipz", "cipz", "agqz", "bgqz", "cgqz", "ahqz",
         "bhqz", "chqz", "aiqz", "biqz", "ciqz", "agrz", "bgrz", "cgrz", "ahrz", "bhrz", "chrz",
         "airz", "birz", "cirz", "agsz", "bgsz", "cgsz", "ahsz", "bhsz", "chsz", "aisz", "bisz",
         "cisz"
    };

    auto result = sl.letterCombinations("2479");
    GTEST_ASSERT_EQ(expected.size(), result.size());
    for (auto value : expected) {
        GTEST_ASSERT_NE(std::find(result.begin(), result.end(), value), result.end());
    }
}

TEST(LETTER_COMBINATIONS_NUMBERS, SameNumberMultipleTimes) {
    Solution sl;
    const auto expected = std::vector<std::string>{
        "aaa", "baa", "caa", "aba", "bba", "cba", "aca", "bca", "cca", "aab", "bab", "cab",
        "abb", "bbb", "cbb", "acb", "bcb", "ccb", "aac", "bac", "cac", "abc", "bbc", "cbc",
        "acc", "bcc", "ccc"
    };

    auto result = sl.letterCombinations("222");
    GTEST_ASSERT_EQ(expected.size(), result.size());
    for (auto value : expected) {
        GTEST_ASSERT_NE(std::find(result.begin(), result.end(), value), result.end());
    }
}

TEST(LETTER_COMBINATIONS_NUMBERS, Number3Test) {
    Solution sl;
    const auto expected = std::vector<std::string>{ "d", "e", "f" };

    auto result = sl.letterCombinations("3");
    GTEST_ASSERT_EQ(expected.size(), result.size());
    for (auto value : expected) {
        GTEST_ASSERT_NE(std::find(result.begin(), result.end(), value), result.end());
    }
}

TEST(LETTER_COMBINATIONS_NUMBERS, Number4Test) {
    Solution sl;
    const auto expected = std::vector<std::string>{ "g", "h", "i" };

    auto result = sl.letterCombinations("4");
    GTEST_ASSERT_EQ(expected.size(), result.size());
    for (auto value : expected) {
        GTEST_ASSERT_NE(std::find(result.begin(), result.end(), value), result.end());
    }
}

TEST(LETTER_COMBINATIONS_NUMBERS, Number5Test) {
    Solution sl;
    const auto expected = std::vector<std::string>{ "j", "k", "l" };

    auto result = sl.letterCombinations("5");
    GTEST_ASSERT_EQ(expected.size(), result.size());
    for (auto value : expected) {
        GTEST_ASSERT_NE(std::find(result.begin(), result.end(), value), result.end());
    }
}

TEST(LETTER_COMBINATIONS_NUMBERS, Number6Test) {
    Solution sl;
    const auto expected = std::vector<std::string>{ "m", "n", "o" };

    auto result = sl.letterCombinations("6");
    GTEST_ASSERT_EQ(expected.size(), result.size());
    for (auto value : expected) {
        GTEST_ASSERT_NE(std::find(result.begin(), result.end(), value), result.end());
    }
}

TEST(LETTER_COMBINATIONS_NUMBERS, Number7Test) {
    Solution sl;
    const auto expected = std::vector<std::string>{ "p", "q", "r", "s" };

    auto result = sl.letterCombinations("7");
    GTEST_ASSERT_EQ(expected.size(), result.size());
    for (auto value : expected) {
        GTEST_ASSERT_NE(std::find(result.begin(), result.end(), value), result.end());
    }
}

TEST(LETTER_COMBINATIONS_NUMBERS, Number8Test) {
    Solution sl;
    const auto expected = std::vector<std::string>{ "t", "u", "v" };

    auto result = sl.letterCombinations("8");
    GTEST_ASSERT_EQ(expected.size(), result.size());
    for (auto value : expected) {
        GTEST_ASSERT_NE(std::find(result.begin(), result.end(), value), result.end());
    }
}

TEST(LETTER_COMBINATIONS_NUMBERS, Number9Test) {
    Solution sl;
    const auto expected = std::vector<std::string>{ "w", "x", "y", "z" };

    auto result = sl.letterCombinations("9");
    GTEST_ASSERT_EQ(expected.size(), result.size());
    for (auto value : expected) {
        GTEST_ASSERT_NE(std::find(result.begin(), result.end(), value), result.end());
    }
}
