#include <gtest/gtest.h>

#include "../src/PeekingIterator.h"

TEST(PEEKING_ITERATOR, Example1Test) {
    std::vector<int> input = {1, 2, 3};
    PeekingIterator iterator(input);

    GTEST_ASSERT_EQ(iterator.next(), 1);
    GTEST_ASSERT_EQ(iterator.peek(), 2);
    GTEST_ASSERT_EQ(iterator.next(), 2);
    GTEST_ASSERT_EQ(iterator.next(), 3);
    GTEST_ASSERT_FALSE(iterator.hasNext());
}
