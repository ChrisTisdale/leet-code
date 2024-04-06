#pragma once

#include <vector>

#include "Iterator.h"

class PeekingIterator : public Iterator {
public:
    explicit PeekingIterator(const std::vector<int> &nums) : Iterator(nums) {
    }

    int peek();
};
