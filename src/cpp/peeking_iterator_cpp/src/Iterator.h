#pragma once

#include <vector>

class Iterator {
    std::vector<int>::const_iterator data;
    const std::vector<int>::const_iterator end;
public:
    explicit Iterator(const std::vector<int> &nums) : data(nums.begin()), end(nums.end()) {
    };

    Iterator(const Iterator &iter) = default;

    virtual int next();

    [[nodiscard]] virtual bool hasNext() const;
};
