#include "Solution.h"
#include <vector>
#include <iostream>

int Solution::search(std::vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }

    return search(nums, 0, static_cast<int>(nums.size() - 1), target);
}

int Solution::search(const std::vector<int>& nums, const int start, const int stop, const int target) const {
    if (start > stop) {
        return -1;
    }

    const int loc = start + (stop - start) / 2;
    if (nums[loc] == target) {
        return loc;
    }

    const auto greater = nums[loc] < target;
    const auto new_start = greater ? loc + 1 : start;
    const auto new_stop = greater ? stop : loc -1;
    return search(nums, new_start, new_stop, target);
}
