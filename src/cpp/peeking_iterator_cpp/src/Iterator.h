#pragma once

#include <vector>

class Iterator {
    std::vector<int> data;
    int index;
public:
    explicit Iterator(const std::vector<int> &nums) : data(nums), index(0) {};

    Iterator(const Iterator &iter) {
        data = iter.data;
        index = iter.index;
    }

    virtual int next();

    [[nodiscard]] virtual bool hasNext() const;
};
