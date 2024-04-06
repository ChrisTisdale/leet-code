#pragma once

#include <vector>

#include "Iterator.h"

class PeekingIterator : public Iterator {
public:
    explicit PeekingIterator(const std::vector<int> &nums) : Iterator(nums), hasPeeked(false), value(-1) {
    }

    int peek();

    int next() override;

    [[nodiscard]] bool hasNext() const override;

private:
    bool hasPeeked;
    int value;
};
