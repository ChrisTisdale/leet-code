#pragma once

#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target);

private:
    int search(const std::vector<int>& nums, const int start, const int stop, const int target) const;
};
