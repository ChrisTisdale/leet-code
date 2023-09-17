#include <gtest/gtest.h>
#include "../src/Solution.h"

TEST(INT_TO_ROMAN, Example1Test) {
	Solution sl;
	const auto result = sl.intToRoman(3);
	GTEST_ASSERT_EQ("III", result);
}

TEST(INT_TO_ROMAN, Example2Test) {
	Solution sl;
	const auto result = sl.intToRoman(58);
	GTEST_ASSERT_EQ("LVIII", result);
}

TEST(INT_TO_ROMAN, Example3Test) {
	Solution sl;
	const auto result = sl.intToRoman(1994);
	GTEST_ASSERT_EQ("MCMXCIV", result);
}

TEST(INT_TO_ROMAN, Example4Test) {
	Solution sl;
	const auto result = sl.intToRoman(20);
	GTEST_ASSERT_EQ("XX", result);
}